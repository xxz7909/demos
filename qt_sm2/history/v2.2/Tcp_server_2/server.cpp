#include "server.h"
#include <QHostAddress>

Server::Server():QTcpServer()
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    TcpClientSocket *tcpclientsocket = new TcpClientSocket();//只要有新的连接就生成一个新的通信套接字
    //将新创建的通信套接字描述符指定为参数socketdescriptor
    tcpclientsocket->setSocketDescriptor(socketDescriptor);

    //将这个套接字加入客户端套接字列表中
    tcpclientsocketList.append(tcpclientsocket);

    //接收到tcpclientsocket发送过来的更新界面的信号
    connect(tcpclientsocket, &TcpClientSocket::updateServer, this, &Server::slotUpdateServer);
    connect(tcpclientsocket, &TcpClientSocket::clientDisconnected, this, &Server::slotClientDsconnect);

    ipClient = tcpclientsocket->peerAddress().toString();
    portClient = tcpclientsocket->peerPort();

    ipClientList.append(ipClient);

   // ui->teRecv->setText(QString("[%1,%2]连接成功").arg(ipClient).arg(portClient));
    qDebug() << "客户端连接"<<ipClient<<" "<<portClient;

}

void Server::slotUpdateServer(int msgType,QString msg)
{

    //msg=msg+tr("%1:%2").arg(ipClient).arg(portClient);
    //将这个信号发送给界面
    emit updateserver(msgType,msg);
    qDebug()<<msgType<<"  "<<msg;
    if(msg.contains("连接"))
    {
        emit sendip_port(ipClient,portClient);
    }

    //将收到的文本信息发送给每个客户端,从套接字列表中找到需要接收的套接字
    if(msgType == ISDATA)
    {
        for(int i = 0; i < tcpclientsocketList.count(); i++)
        {
         /*   QTcpSocket *item = tcpclientsocketList.at(i);

            item->write(msg.toUtf8().data());

            qDebug() << "客户端[" << i+1 << "]IP:" << item->peerAddress().toString();*/
        }
    }

}

void Server::slotClientDsconnect(int descriptor)
{

    for(int i = 0; i < tcpclientsocketList.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketList.at(i);
        if(item->socketDescriptor() == descriptor)
        {
            QString ip=tcpclientsocketList[i]->peerAddress().toString();
            quint16 port=tcpclientsocketList[i]->peerPort();
            emit disconnect_sendip_port(ip,port);
            tcpclientsocketList.removeAt(i);//如果有客户端断开连接， 就将列表中的套接字删除
            return;
        }
    }
    return;
}
