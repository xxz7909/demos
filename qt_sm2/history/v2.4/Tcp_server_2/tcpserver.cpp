#include "tcpserver.h"
#include "ui_tcpserver.h"

#include <QDebug>

int flag=0;
int flag1=0;
Tcpserver::Tcpserver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tcpserver)
{
    ui->setupUi(this);
    ItemModel = new QStandardItemModel(this);
    serverNew  = new Server();
    connect(serverNew, &Server::updateserver, this, &Tcpserver::slotUpdateServer);
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showinfo(QModelIndex)));
    ui->btnSelectFile->setEnabled(false);
    ui->btnSendFile->setEnabled(false);
    connect(serverNew,&Server::sendip_port,this,&Tcpserver::addlist);
    connect(serverNew,&Server::disconnect_sendip_port,this,&Tcpserver::removelist);
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortHeader(int)));
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(serverNew,&Server::updateshell,this,&Tcpserver::soltupdateshell);
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


        //进行第一次判断，获取用户名
        if(msg.contains("连接"))
        {
            int k1=msg.indexOf('-');
            userName=msg.mid(0,k1);


        }
    }
    else if(msgType == ISFILE)
    {
        //ui->tbRecv->setText(msg);
        ui->tbRecv->append(msg);
        int k1=msg.indexOf(':');
        int k2=msg.indexOf("txt",k1+1);
        info_filename=msg.mid(k1+1,k2+2-k1);

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
void Tcpserver::addlist(QString ip,quint16 port)
{

    QString temp = QString("%1:%2:%3").arg(userName).arg(ip).arg(port);
    QStandardItem *item = new QStandardItem(temp);
    ItemModel->appendRow(item);
    ui->listView->setModel(ItemModel);

}
void Tcpserver::showinfo(QModelIndex index)
{
    QString strtemp;
    strtemp=index.data().toString();
    display_now=strtemp;
    int k3=strtemp.indexOf(':');
    QString user=strtemp.mid(0,k3);
    QString filename_jiemi=tr("/home/wang/server/info_decryptor_%1.txt").arg(user);
    //ui->textEdit->setText("kaishiyunxing");
    QFile f(filename_jiemi);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&f);
    in.readLine();

    in.readLine();//1  除去第一行自己加入的之后代码的第一行
    QString b = in.readLine();//2vendor_id
    in.readLine();//3
    in.readLine();//4
    QString a = in.readLine();//5model name
    in.readLine();//6
    in.readLine();//7

    QString c=in.readLine();//8 cpu_mhz
    QString d= in.readLine();//9 cache size
    in.readLine();
    in.readLine();
    in.readLine();
    QString e=in.readLine();//13  cpu_cores
    for (int i=0 ;i<95;i++)
    {in.readLine();}//前往第109行，准备读取version文件
    QString g = in.readLine();//110
    ui->textEdit->setText( a+"\r\r"+b+"\r\r"+c+"\r\r"+d+"\r\r"+e+"\r\r"+ "Operating System Info: "+ g);

    //
    //第3个界面第56行。modules文件
    //

    QString row1;
    QString row2;
    QString row3;
    QString line;
    int     firstblank;
    int     secondblank;
    int     thirdblank;
    int     w;
   for(w=0;w<flag;w++)
   {
   ui->tableWidget_2->removeRow(flag);
   }

//    while(!(line=="wangzhengqi"))
//    {
//        line=in.readLine();
//    }

    line=in.readLine();//111行
    line=in.readLine();//112行
    w=0;
    while(!(line == "wanghao"))
    {

        firstblank=line.indexOf(" ");
        row1=line.mid(0,firstblank);
        secondblank=line.indexOf(" ",firstblank+1);
        row2=line.mid(firstblank,secondblank-firstblank);
        thirdblank=line.indexOf(" ",secondblank+1);
        row3=line.mid(secondblank,thirdblank-secondblank);
        ui->tableWidget_2->insertRow(w) ;
        ui->tableWidget_2->setItem(w,0,new QTableWidgetItem(row1));
        ui->tableWidget_2->setItem(w,1,new QTableWidgetItem(row2));
        ui->tableWidget_2->setItem(w,2,new QTableWidgetItem(row3));
        line=in.readLine();
        w++;
    }
    flag=w;
    for(w=0;w<flag;w++)
    {
    ui->tableWidget_2->removeRow(flag);
    }

     int     total1,total2;
     int     used1,used2;
     int     free1,free2;
     int     k1,k2;

     line=in.readLine();
     line=line.right(17);//获取memtotal
     ui->inlabel_3->setText(line);
     k1=line.indexOf("k");
     k1=k1-1;
     line=line.mid(0,k1);
     total1=line.toULong();

     line=in.readLine();
     line=line.right(16);//获取memfree
     free1=line.toULong();
     ui->inlabel_2->setText(line);

     k1=line.indexOf("k");
     k1=k1-1;
     line=line.mid(0,k1);
     free1=line.toULong();

     for(int j=0;j<12;j++)
     {
         in.readLine();
     }
     line=in.readLine();
     line=line.right(18);
     ui->outlabel_3->setText(line);//获取swaptotal
     k2=line.indexOf("k");
     k2=k2-1;
     line=line.mid(1,k2);//要非常注意，这里的索引应该从1开始。
     total2=line.toULong();

     line=in.readLine();//SWAPfree
     line=line.right(18);
     free2=line.toULong();
     ui->outlabel_2->setText(line);

     k2=line.indexOf("k");
     k2=k2-1;
     line=line.mid(0,k2);
     free2=line.toULong();

     used1=total1-free1;
     used2=total2-free2;

     line.setNum(used1);
     line=line+"kB";
     ui->inlabel_1->setText(line);
     line.setNum(used2);
     line=line+"kB";
     ui->outlabel_1->setText(line);

    //内存交换区进度条
     unsigned long int mem,swap;
     mem=(used1*100)/total1;
     swap=(used2*100)/total2;
     ui->progressBar_2->setValue(mem);
     ui->progressBar_3->setValue(swap);

    while(!(line=="wanghao"))//.isNull()
    {
       line=in.readLine();
    }


    int blank1,blank2,blank3,blank4,blank5,blank6,blank7;
    QString cpu1,cpu2,cpu3,cpu4,cpu5,cpu6,cpu7;
    int cpun1,cpun2,cpun3,cpun4,cpun5,cpun6,cpun7,used3;

    line=in.readLine();
    blank1=line.indexOf(" ",5);
    blank2=line.indexOf(" ",blank1+1);
    blank3=line.indexOf(" ",blank2+1);
    blank4=line.indexOf(" ",blank3+1);
    blank5=line.indexOf(" ",blank4+1);
    blank6=line.indexOf(" ",blank5+1);
    blank7=line.indexOf(" ",blank6+1);

    cpu1=line.mid(5,blank1-5);
    cpu2=line.mid(blank1,blank2-blank1);
    cpu3=line.mid(blank2,blank3-blank2);
    cpu4=line.mid(blank3,blank4-blank3);
    cpu5=line.mid(blank4,blank5-blank4);
    cpu6=line.mid(blank5,blank6-blank5);
    cpu7=line.mid(blank6,blank7-blank6);

    cpun1=cpu1.toULong();
    cpun2=cpu2.toULong();
    cpun3=cpu3.toULong();
    cpun4=cpu4.toULong();
    cpun5=cpu5.toULong();
    cpun6=cpu6.toULong();
    cpun7=cpu7.toULong();


    used3=((cpun1+cpun2+cpun3+cpun5+cpun6+cpun7)*100)/(cpun1+cpun2+cpun3+cpun4+cpun5+cpun6+cpun7);
    line.setNum(used3);
    line=line+"%";
    ui->cpulabel->setText(line);
    ui->progressBar->setValue(used3);

    while(!(line == "wanghao"))
    {
       line=in.readLine();
    }


    //
    //第2个界面,是每一个进程中的stat
    //


        int i=2;
        QDir qd("/proc");
        QStringList qslist=qd.entryList();
        QString pname,pstate,ppoi,pmem;
        int code1,code2,code3,codep,codep2,codem,codem2;
        QString qs=qslist[i];
        int j;

        while((qs[0]<='9')&&(qs[0]>='1'))
        {
            int n;
            QString pid=qs;
            qs="/proc/"+qs;
            qs=qs+"/stat";
            QFile f5(qs);
            f5.open(QIODevice::ReadOnly | QIODevice::Text);


            QString process = in.readLine();
            code1=process.indexOf(" ");
            code2=process.indexOf(" ",code1+1);
            code3=process.indexOf(" ",code2+1);
            codep=process.indexOf(" ",code3+1);

            for(n=0;n<13;n++)
            {
                codep=process.indexOf(" ",codep+1);
            }

            codep2=process.indexOf(" ",codep+1);
            codem=process.indexOf(" ",codep2+1);

            for(n=0;n<3;n++)
            {
                codem=process.indexOf(" ",codem+1);
            }

            codem2=process.indexOf(" ",codem+1);
            pname=process.mid(code1,code2-code1);
            pstate=process.mid(code2,code3-code2);
            ppoi=process.mid(codep,codep2-codep);
            pmem=process.mid(codem,codem2-codem);

            ui->tableWidget->insertRow(0) ;
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(pid));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(pname));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(pstate));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(ppoi));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(pmem));
            i++;
            qs=qslist[i];
        }
           flag1=i-2;

           for(j=0;j<=flag1;j++)
           {
           ui->tableWidget->removeRow(flag1);
           }
}
void Tcpserver::removelist(QString ip,quint16 port)
{
    if(display_now.contains(tr("%1:%2").arg(ip).arg(port)))
    {
        ui->textEdit->clear();
        ui->tableWidget->clear();
        ui->tableWidget_2->clear();
        ui->tab_3->hide();
    }
    int row_num = ui->listView->model()->rowCount();
    // 删除存储在listview中的客户端信息
    for(int j=0;j<row_num;j++)
    {
        // row_idx为该行索引序号, column_idx为该列索引序号,两者都以0开始
        QString str = ui->listView->model()->index(j,0).data().toString();
        int maohao1=str.indexOf(':');
        QString peer=str.mid(maohao1+1);


        if(peer==(tr("%1:%2").arg(ip).arg(port)))
        {
            ItemModel->removeRow(j);
            break;
        }

    }
}
void Tcpserver::sortHeader(int index)
{
    if (index == 2)
    {
        ui->tableWidget->sortItems(index, Qt::DescendingOrder);
        return;
    }
    ui->tableWidget->sortItems(index, Qt::AscendingOrder);
}

void Tcpserver::on_lineEdit_returnPressed()
{
    QString _str = ui->lineEdit->text();
        ui->textBrowser->append("Linux:~$ " + _str);
        QString strtemp;
        strtemp=ui->listView->selectionModel()->currentIndex().data().toString();
        int k3=strtemp.indexOf(':');
        QString peer=strtemp.mid(k3+1);
        for(int i = 0; i < serverNew->tcpclientsocketList.count(); i++)
        {
            QTcpSocket *item = serverNew->tcpclientsocketList.at(i);
            QString ip_port=tr("%1:%2").arg(item->peerAddress().toString()).arg(item->peerPort());
            if(peer==ip_port)//可向指定IP发送信息
            {
                outStream.setDevice(item);
                outStream.setVersion(QDataStream::Qt_5_9);

                outStream << ISCMD << _str.toUtf8();
                //item->write(msg.toUtf8().data());
                //item->flush();
                //qDebug() <<msg.toUtf8().data() << "  " << ISCMD;

                //qDebug() << "客户端[" << i << "]IP:" << item->peerAddress().toString();
            }
        }
        //m_process->write(ui->lineEdit->text().toLocal8Bit() + '\n');
        ui->lineEdit->clear();
}
void Tcpserver::soltupdateshell(QString str)
{
    //ui->textBrowser->append(QString::fromLocal8Bit(str));
    ui->textBrowser->append(str);
}
