#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include <QList>
#include <QStringList>
#include "tcpclientsocket.h"



class Server : public QTcpServer
{
    Q_OBJECT //为了实现信号和槽的通信
public:
    Server();
    QList<TcpClientSocket*> tcpclientsocketList;
    QStringList ipClientList;
    QList<quint16*> portClientList;

protected:
    void incomingConnection(qintptr socketDescriptor);//只要出现一个新的连接，就会自动调用这个函数
protected slots:
    void slotUpdateServer(int msgType,QString);//用来处理tcpclient发过来的信号
    void slotClientDsconnect(int);

signals:
    void updateserver(int msgType, QString);//发送信号给界面，让界面更新信息

};

#endif // SERVER_H
