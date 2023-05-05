#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QDataStream>

#include <QFile>
#include <QFileInfo>

#define ISDATA 1
#define ISFILE 2

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT //添加这个宏是为了实现信号和槽的通信
public:
    TcpClientSocket();

    void recv_reset();

    QDataStream inStream;

    QFile *receiveFile;
    QString fileName;
    QString filePath;

    qint64 fileBytes;       //文件总大小

    qint64 fileSize;         //文件大小，换算成KB/MB
    qint64 sizeReceived;     //接收的大小，换算成KB/MB

    //缓冲区数据
    QByteArray inBlock;

    QString username;
protected slots:
    void receiveData();//处理readyRead信号读取数据
    void slotClientDisconnected();//客户端断开连接触发disconnected信号，这个槽函数用来处理这个信号

signals:
    void updateServer(int msgType,QString);//用来告诉tcpserver需要跟新界面的显示
    void clientDisconnected(int); //告诉server有客户端断开连接
};

#endif // TCPCLIENTSOCKET_H
