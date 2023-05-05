#include "tcpserver.h"
#include "ui_tcpserver.h"

#include <QDebug>


Tcpserver::Tcpserver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tcpserver)
{
    ui->setupUi(this);

    serverNew  = new Server();
    connect(serverNew, &Server::updateserver, this, &Tcpserver::slotUpdateServer);

    ui->btnSelectFile->setEnabled(false);
    ui->btnSendFile->setEnabled(false);
}

Tcpserver::~Tcpserver()
{
    serverNew->close();
    serverNew->deleteLater();
    delete ui;
}


void Tcpserver::slotUpdateServer(int msgType,QString msg)
{
    if(msgType == ISDATA)
    {
        ui->tbRecv->append(msg);
    }
    else if(msgType == ISFILE)
    {
        //ui->tbRecv->setText(msg);
        ui->tbRecv->append(msg);
    }

}

void Tcpserver::on_btnListen_clicked()
{
    if(ui->btnListen->text() == tr("侦听"))
    {
        if(ui->lePort->text() != NULL)
        {
            //输入框获取端口号
            int port = ui->lePort->text().toInt();

            //监听指定端口
            if(!serverNew->listen(QHostAddress::AnyIPv4,port))
            {
                qDebug() << serverNew->errorString();
                return;
            }
            //修改按键文字
            ui->btnListen->setText("取消侦听");
            ui->btnSelectFile->setEnabled(true);
            qDebug() << "侦听成功";
        }
    }
    else
    {
        //断开已有连接
        for(int i = 0; i < serverNew->tcpclientsocketList.count(); i++)
        {
            QTcpSocket *item = serverNew->tcpclientsocketList.at(i);
            item->abort();
        }

        //取消侦听
        serverNew->close();
        //修改按键文字
        ui->btnListen->setText("侦听");
        //发送按键失能
        ui->btnSend->setEnabled(false);
    }

}

void Tcpserver::on_btnSend_clicked()
{
    QString msg = ui->teSend->toPlainText();

    msg = "server："+msg;
    qDebug() << "Send: "<< msg;

    if(msg == NULL)
    {
        return;
    }

    for(int i = 0; i < serverNew->tcpclientsocketList.count(); i++)
    {
        QTcpSocket *item = serverNew->tcpclientsocketList.at(i);

        //if(item->peerAddress().toString() == "192.168.xxx.xxx")//可向指定IP发送信息
        {
            outStream.setDevice(item);
            outStream.setVersion(QDataStream::Qt_5_9);

            outStream << ISDATA << msg.toUtf8().data();
            //item->write(msg.toUtf8().data());
            //item->flush();
            qDebug() <<msg.toUtf8().data() << "  " << ISDATA;

            qDebug() << "客户端[" << i << "]IP:" << item->peerAddress().toString();
        }
    }
}

void Tcpserver::on_btnClearMsg_clicked()
{
    ui->tbRecv->clear();
}



void Tcpserver::on_btnSelectFile_clicked()
{
    QString fileInfo;

    fileInfo = QFileDialog::getOpenFileName(this);

    if(!fileInfo.isEmpty())
    {
        QFileInfo info(fileInfo);

        fileName = info.fileName();
        filePath = info.filePath();
        fileBytes = info.size();
        if(fileBytes>1024*1024) //以MB为单位
        {
            fileSize = (float)fileBytes/(1024*1024);
        }
        else if(fileBytes>1024){
            fileSize = (float)fileBytes/(1024);
        }
        else{
            fileSize = (float)fileBytes;
        }
        sendFile = new QFile(fileInfo);
        ui->btnSendFile->setEnabled(true);
        ui->tbRecv->append(QString("[%1] size = %2打开成功").arg(fileName).arg(fileBytes));
    }
}

void Tcpserver::on_btnSendFile_clicked()
{
    ui->btnSendFile->setEnabled(false);
    sizeWritten = 0;

    if(!sendFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "0";
        return;
    }

    fileSize = sendFile->size();
    QFileInfo info(sendFile->fileName());
    fileName = info.fileName();

    for(int i = 0; i < serverNew->tcpclientsocketList.count(); i++)
    {
        QTcpSocket *item = serverNew->tcpclientsocketList.at(i);

        //if(item->peerAddress().toString() == "192.168.xxx.xxx")//可向指定IP发送文件
        {
            outStream.setDevice(item);
            outStream.setVersion(QDataStream::Qt_5_9);

            //发送文件
            outStream << ISFILE;

            outStream << fileBytes << fileName;

            qDebug() << fileBytes << "  " <<fileName;
            QByteArray arry = sendFile->read(fileBytes);
            int size = arry.size();
            outStream.writeRawData(arry.constData(),size);
            ui->tbRecv->append(QString("[%1] 开始发送").arg(fileName));

            //防止TCP黏包文件
            //需要通过定时器延时20ms
            timer.start(20);
        }
    }
}
