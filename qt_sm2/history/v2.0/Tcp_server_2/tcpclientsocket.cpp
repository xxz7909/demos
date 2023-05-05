#include "tcpclientsocket.h"

#include <QDebug>

//指定接收文件存放路径
#define FILE_SAVE_PATH "/home/wang/server/"
//#define FILE_SAVE_PATH ""

TcpClientSocket::TcpClientSocket()
{
    //客户端发送数据过来就会触发readyRead信号
    connect(this, &QIODevice::readyRead, this, &TcpClientSocket::receiveData);
    connect(this, &TcpClientSocket::disconnected, this, &TcpClientSocket::slotClientDisconnected);

    inStream.setDevice(this);
    inStream.setVersion(QDataStream::Qt_5_9);

    recv_reset();
}

void TcpClientSocket::recv_reset()
{
    fileName.clear();
    fileBytes = 0;
    sizeReceived = 0;
}

void TcpClientSocket::receiveData()
{ 
    QByteArray buffer;
    static int msgType;

    qDebug() << "receive--00  "<<fileBytes;

    //qDebug() << "receive--01  "<<this->bytesAvailable();

    if((0 == fileBytes) && (this->bytesAvailable() > sizeof(qint64)))
    {
        //读取缓冲区数据
        //buffer = readAll();
        inStream >> msgType;
        qDebug() << "~~~"<<msgType;

        //根据接收信息类型不同分别处理
        switch(msgType)
        {
            case ISDATA:
                inStream >> buffer;
                if(!buffer.isEmpty())
                {
                    QString str = tr(buffer);
                    //刷新UI
                    emit updateServer(msgType,str);
                    return;
                }

            break;

            case ISFILE:
                inStream >> fileBytes >> fileName;

                receiveFile = new QFile();//创建一个文件，用来接收文件信息
                receiveFile->setFileName(FILE_SAVE_PATH+fileName);//指定存放路径
                if(!receiveFile->open(QIODevice::WriteOnly))
                {
                    qCritical() <<receiveFile->errorString();
                }

                QString str = QString("开始接收文件[%1]").arg(fileName);
                //刷新UI
                emit updateServer(msgType,str);
            break;
        }
    }

    qint64 size = qMin(this->bytesAvailable(),(fileBytes - sizeReceived));

    //QByteArray arry(size,0);
    inBlock.resize(size);

    //qDebug() << "Size of receiveFile is " << size;
    inStream.readRawData(inBlock.data(),size);
    receiveFile->write(inBlock);

    sizeReceived += size;
    qDebug()<<"sizeReceived = "<<sizeReceived;
    qDebug()<<"fileBytes = "<<fileBytes;
    qDebug() << "!!!!"<<msgType;
    if(sizeReceived == fileBytes)
    {
        receiveFile->close();
        QFileInfo receiveInfo(fileName);

        QString str = QString("[%1]接收成功").arg(fileName);       
        //刷新UI
        emit updateServer(msgType,str);

        recv_reset();

    }
    inBlock.resize(0);

}

void TcpClientSocket::slotClientDisconnected()
{
    emit clientDisconnected(this->socketDescriptor());
}
