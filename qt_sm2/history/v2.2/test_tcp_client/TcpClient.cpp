#include "TcpClient.h"
#include "ui_TcpClient.h"

#include <QString>
#include <QDebug>
#include <QHostInfo>
#include <aestools.h>

//指定接收文件存放路径
#define FILE_SAVE_PATH "/home/wang/client/"
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
            timer.start(200);
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

    qDebug() << send_s.fileBytes << "  " <<send_s.fileName;
    QByteArray arry = send_s.sendFile->read(send_s.fileBytes);
    int size = arry.size();
    send_s.outStream.writeRawData(arry.constData(),size);
    ui->tbRecv->append(QString("[%1] 开始发送").arg(send_s.fileName));
    timer.start(20);
    on_btnSend_clicked();

//    socket->write("");


}
