#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAbstractSocket>
#include <QTcpSocket>

#include <QFile>
#include <QTimer>
#include <QFileDialog>

#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

private:
    Ui::TcpClient *ui;
    QTcpSocket *socket;

    enum m_mgsType
    {
        ISDATA = 1,
        ISFILE,
    };

    enum clientStatus
    {
        DISCONNECT = 0,
        CONNECTED,
    };

    struct clientInfoStruct
    {
        QString IP;
        QString port;

        int state;
    };

    struct sendStruct
    {
        QDataStream outStream;

        bool isSendFile;        //发送的是文件
        QFile *sendFile;
        QString fileName;
        QString filePath;

        qint64 fileBytes;       //文件总大小
        qint64 sizeWritten;      //已发送的大小
        qint64 sizetoWrite;      //未发送的大小


    } send_s ;

    struct receiveStruct
    {
        QDataStream inStream;

        QFile *receiveFile;
        QString fileName;
        QString filePath;

        qint64 fileBytes;       //文件总大小
        qint64 sizeReceived;     //接收的大小

        //缓冲区数据
        QByteArray inBlock;
    }receive_s;

    QString userName;
    QTimer timer;

signals:
    void newClient();       //客户端信息变更信号
    void updataProgress(qint64,qint64,int); //更新发送进度信号
    void newClientInfo(QString,int,int);    //更新客户端信息


private slots:
    void on_btnConnect_clicked();
    void on_btnSend_clicked();

    void socket_Read_Data();        //接收数据
    void socket_Disconnected();     //断开连接

    void on_btnSelectFile_clicked();
    void on_btnSendFile_clicked();
    void sendallinfo(); //自己加的

private:
    void send_reset();
    void recv_reset();



};
#endif // MAINWINDOW_H
