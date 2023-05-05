#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QStandardItemModel>
#include <QModelIndex>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void tabWidget_selected();
private:
   Ui::Widget *ui;
   QTcpServer tcpServer;
   QTcpSocket *tcpServerConnection;
   qint64 totalBytes;  //存放总大小信息
   qint64 bytesReceived;   //已收到数据的大小
   qint64 fileNameSize;   //文件名的大小信息
   QString fileName;    //存放文件名
   QFile *localFile;    //本地文件
   QByteArray inBlock;   //数据缓冲区
   QString message;   //存放从节点接收到的字符串
   quint16 blockSize;   //存放文件的大小信息
   QStringListModel *Model;
   QStandardItemModel *ItemModel;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_startButton_clicked();
    void start();   //开始监听
    void acceptConnection();  //建立连接
    void updateServerProgress();  //更新进度条,接收数据
    void displayError(QAbstractSocket::SocketError socketError);//显示错误
    void readMessage();  //接收消息
    void sendMessage();



    void showinfo(QModelIndex index);
};

#endif // WIDGET_H
