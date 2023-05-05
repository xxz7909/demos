#ifndef TCPSERVERR_H
#define TCPSERVERR_H

#include <QWidget>
#include "server.h"

#include <QFile>
#include <QTimer>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Tcpserver; }
QT_END_NAMESPACE

class Tcpserver : public QWidget
{
    Q_OBJECT

public:
    Tcpserver(QWidget *parent = nullptr);
    ~Tcpserver();

private:
    Ui::Tcpserver *ui;
    Server *serverNew;

    QDataStream outStream;

    QFile *sendFile;
    QString fileName;
    QString filePath;

    qint64 fileBytes;       //文件总大小

    float fileSize;         //文件大小，换算成KB/MB
    float sizeWritten;      //已发送的大小，换算成KB/MB
    float sizetoWrite;      //未发送的大小，换算成KB/MB
    float sizeReceived;     //接收的大小，换算成KB/MB

    //缓冲区数据
    QByteArray inBlock;
    QByteArray outBlock;

    QTimer timer;

protected slots:
    void slotUpdateServer(int msgType,QString);//接收到server发过来的信号就更新界面的信息


private slots:
    void on_btnListen_clicked();
    void on_btnSend_clicked();
    void on_btnClearMsg_clicked();
    void on_btnSendFile_clicked();
    void on_btnSelectFile_clicked();
};
#endif // TCPSERVERR_H

