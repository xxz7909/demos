#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <stdlib.h>
#include <aestools.h>

using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QProcess process;//=ui->lineEdit->text();
    process.execute("TASKKILL/IM kacpid/F");
    ui->sendButton_2->setEnabled(false);
    loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpClient = new QTcpSocket(this);

    QFile f("/proc/cpuinfo");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile f1("/proc/version");
    f1.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile f2("/proc/modules");
    f2.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile f3("/proc/meminfo");
    f3.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile f4("/proc/stat");
    f4.open(QIODevice::ReadOnly | QIODevice::Text);

    int i=2;
    QString ab ;
    QDir qd("/proc");
    QStringList qslist=qd.entryList();
    QString qs=qslist[i];
    while((qs[0]<='9')&&(qs[0]>='1'))
        {

            qs="/proc/"+qs;
            qs=qs+"/stat";
            QFile f5(qs);
            f5.open(QIODevice::ReadOnly | QIODevice::Text);
            ab+= f5.readAll();

            i++;
            qs=qslist[i];
         }

    QString a = f.readAll() + f1.readAll() + f2.readAll() +"wanghao"+"\n"+ f3.readAll()+ "wanghao"+"\n"+f4.readAll()+"wanghao"+"\n"+ab;
    f.close();f1.close();f2.close();f3.close();f4.close();
    ui->textEdit->append(a);
//    QByteArray abb=a.toLatin1();
//    char *mingwen=abb.data();
//    char miwen[1024]={0};
//    char jiemi[1024]={0};
//    AesTools *aes=new AesTools;
//    aes->OnAesEncrypt((LPVOID)mingwen, strlen(mingwen), (LPVOID)miwen);
//    QByteArray bb=(QByteArray)miwen;
//    QString mim=(QString)bb;
//    ui->textEdit->append(mim);
   ///新建文件来存储信息到指定目录，而后进行发送
    QFile file("/home/wang/info_mingwen.txt");
    bool fileok =file.open(QIODevice::WriteOnly);
    if(fileok==true)
    {
       file.write(a.toStdString().data());
    }
    else
    {
        ui->lineEdit->setText("dakaiwenjianshibai");
        return;
    }

    file.close();
        AesTools *aes=new AesTools;
    //设置密钥，保证加密和解密的密钥一致
//        UCHAR key[102400] = "xyz";
//        UCHAR *p = key;
//        DWORD keySize = strlen((char *)key);
//        //进行密钥初始化
//        aes->InitializePrivateKey(keySize, p);

    aes->FileEncryptor("/home/wang/info_mingwen.txt","/home/wang/info.txt");

//    QFile file2("/home/wang/info_miwen.txt");
//    bool fileok2 =file2.open(QIODevice::ReadOnly);
//    if(fileok2==true)
//    {
//        QByteArray string_miwen=file2.read(file2.bytesAvailable());
//        ui->textEdit_miwen->append(string_miwen.toBase64());
//    }


//    file2.close();


        connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
        //当连接服务器成功时,发出 connected()信号,我们开始传送文件

        connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,
    SLOT(updateClientProgress(qint64)));

        connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,
                SLOT(displayError(QAbstractSocket::SocketError)));

        connect(tcpClient,SIGNAL(readyRead()),this,
        SLOT(readMessage()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::startTransfer() //实现文件大小等信息的发送
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    totalBytes = localFile->size();
    //文件总大小
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    QString currentFileName = fileName.right(fileName.size() -
fileName.lastIndexOf('/')-1);
    sendOut << qint64(0) << qint64(0) << currentFileName;
    //依次写入总大小信息空间,文件名大小信息空间,文件名
    totalBytes += outBlock.size();
    //这里的总大小是文件名大小等信息和实际文件大小的总和
  sendOut.device()->seek(0);
  sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));
  //返回 outBolock 的开始,用实际的大小信息代替两个 qint64(0)空间
  bytesToWrite = totalBytes - tcpClient->write(outBlock);
  //发送完头数据后剩余数据的大小
  ui->clientStatusLabel->setText(tr("已连接"));
  outBlock.resize(0);
  ui->sendButton_2->setEnabled(true);

}
void Widget::updateClientProgress(qint64 numBytes) //更新进度条,实现文件的传送
{


    bytesWritten += (int)numBytes;
    //已经发送数据的大小
    if(bytesToWrite > 0) //如果已经发送了数据
    {
         outBlock = localFile->read(qMin(bytesToWrite,loadSize));
      //每次发送 loadSize 大小的数据,这里设置为 4KB,如果剩余的数据不足 4KB,
      //就发送剩余数据的大小
         bytesToWrite -= (int)tcpClient->write(outBlock);
       //发送完一次数据后还剩余数据的大小
         outBlock.resize(0);
         //清空发送缓冲区
    }
    else
    {
         localFile->close(); //如果没有发送任何数据,则关闭文件
    }

    if(bytesWritten == totalBytes) //发送完毕
    {

        localFile->close();
        //tcpClient->close();
    }

  }
void Widget::displayError(QAbstractSocket::SocketError) //显示错误
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();

    ui->clientStatusLabel->setText(tr("客户端就绪"));
    ui->sendButton->setEnabled(true);
}

void Widget::on_sendButton_clicked()
{


    fileName = "/home/wang/info.txt";
    bytesWritten = 0;
    //初始化已发送字节为 0
    ui->clientStatusLabel->setText(tr("连接中..."));
    tcpClient->connectToHost(ui->hostLineEdit->text(),
                             ui->portLineEdit->text().toInt());//连接
}

void Widget::readMessage()
{
    blockSize = 0; //初始化其为 0
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_4_6);

  if(blockSize==0) //如果是刚开始接收数据
  {
      //判断接收的数据是否有两字节,也就是文件的大小信息
      //如果有则保存到 blockSize 变量中,没有则返回,继续接收数据
      if(tcpClient->bytesAvailable() < (int)sizeof(quint16)) return;
      in >> blockSize;
  }
  if(tcpClient->bytesAvailable() < blockSize) return;
  //如果没有得到全部的数据,则返回,继续接收数据
  in >> message;
  //将接收到的数据存放到变量中
  if(!message.contains("kill "))
  {
      ui->clientStatusLabel->setText("Center: "+ message);//显示接收到的数据
  }
  else
  {
      //message.append(" bash -c");
      system(message.toStdString().data());
  }

}
void Widget::on_sendButton_2_clicked()
{
    sendMessage();
}
void Widget::sendMessage()
{
    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);
    //使用数据流写入数据
    out.setVersion(QDataStream::Qt_4_6);
    //设置数据流的版本,客户端和服务器端使用的版本要相同
    out<<(quint16) 0;
    out<<ui->lineEdit->text();
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    tcpClient->write(block);

}
