#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include<aestools.h>
int flag=0;
int flag1=0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->hide();
    ui->pushButton->setEnabled(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    ItemModel = new QStandardItemModel(this);
    connect(&tcpServer,SIGNAL(newConnection()),this,
    SLOT(acceptConnection()));
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showinfo(QModelIndex)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMessage()
{
    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);//使用数据流写入数据
    out.setVersion(QDataStream::Qt_4_6);//设置数据流的版本,客户端和服务器端使用的版本要相同
    out<<(quint16) 0;
    out<<ui->lineEdit->text();
    out.device()->seek(0);
    out <<(quint16)(block.size()-sizeof(quint16));
    tcpServerConnection->write(block);
}

void Widget::readMessage()
{
    blockSize = 0; //初始化其为 0
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);

  if(blockSize==0) //如果是刚开始接收数据
  {

      if(tcpServerConnection->bytesAvailable() < (int)sizeof(quint16)) return;
      in >> blockSize;
  }
  if(tcpServerConnection->bytesAvailable() < blockSize) return;
  //如果没有得到全部的数据,则返回,继续接收数据

  in >> message;
  //将接收到的数据存放到变量中
//  int     k1,k2;
//  k1=message.indexOf(":");
//  k2=message.indexOf(':',k1+1)
//  line=line.mid(0,k1);



   ui->serverStatusLabel->setText("Client: "+message);
       //显示接收到的数据



}

void Widget::start() //开始监听
{
  ui->startButton->setEnabled(false);
  bytesReceived =0;
  if(!tcpServer.listen(QHostAddress::LocalHost,ui->port->text().toInt()))
  {
      qDebug() << tcpServer.errorString();
      close();
      return;
  }
  ui->serverStatusLabel->setText(tr("监听ing"));

}

void Widget::acceptConnection()  //接受连接
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    QString ip = tcpServerConnection->peerAddress().toString();
            qint16  port = tcpServerConnection->peerPort();
            QString temp = QString("%1:%2").arg(ip).arg(port);

            ui->textBrowser->append(temp);
    ui->pushButton->setEnabled(true);

    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpServerConnection,
    SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    //ui->serverStatusLabel->setText(tr("已接受连接"));
    tcpServer.close();
}

void Widget::updateServerProgress() //接收数据
{
  QDataStream in(tcpServerConnection);
  in.setVersion(QDataStream::Qt_4_6);
  if(bytesReceived <= sizeof(qint64)*2)
  {
       if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)
           && (fileNameSize == 0))
       { //接收数据总大小信息和文件名大小信息
           in >> totalBytes >> fileNameSize;
           bytesReceived += sizeof(qint64) * 2;
       }
       if((tcpServerConnection->bytesAvailable() >= fileNameSize)
           && (fileNameSize != 0))
       {  //接收文件名,并建立文件
           in >> fileName;
           ui->serverStatusLabel->setText(tr("接收数据 %1 ...").arg(fileName));
           bytesReceived += fileNameSize;
           localFile = new QFile(fileName);
           if(!localFile->open(QFile::WriteOnly))
           {
               qDebug() << "open file error!";
               return;
            }
        }
        else return;
   }
   if(bytesReceived < totalBytes)
   {  //如果接收的数据小于总数据,那么写入文件

       bytesReceived += tcpServerConnection->bytesAvailable();
       inBlock = tcpServerConnection->readAll();
       localFile->write(inBlock);
       inBlock.resize(0);
   }
   ui->serverProgressBar->setMaximum(totalBytes);
   ui->serverProgressBar->setValue(bytesReceived);
   //更新进度条
   if(bytesReceived == totalBytes)
   { //接收数据完成时
    localFile->close();
    ui->startButton->setEnabled(true);
    ui->serverStatusLabel->setText(tr("接收数据 %1 成功!").arg(fileName));
    AesTools *aes=new AesTools;
    aes->FileDecryptor("/home/wang/BYSJ_wang_main1.1/build-tcpReceiver-Desktop_Qt_5_9_0_GCC_64bit-Debug/info.txt",
                       "/home/wang/BYSJ_wang_main1.1/build-tcpReceiver-Desktop_Qt_5_9_0_GCC_64bit-Debug/info_decryptor.txt");
    tabWidget_selected();

   }
    ui->tabWidget->show();


}

void Widget::displayError(QAbstractSocket::SocketError) //错误处理
{
    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->serverProgressBar->reset();
    ui->serverStatusLabel->setText(tr("就绪"));
    ui->startButton->setEnabled(true);
}

void Widget::on_startButton_clicked()
{
    start();
}

//监控模块核心代码
void Widget::tabWidget_selected( )
{
    //ui->textEdit->setText("kaishiyunxing");
    QFile f("/home/wang/BYSJ_wang_main1.1/build-tcpReceiver-Desktop_Qt_5_9_0_GCC_64bit-Debug/info_decryptor.txt");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&f);
    QString baseinfo=in.readLine();
    QStringList strl=baseinfo.split(":");


    QStandardItem *item = new QStandardItem(strl.at(1));
    ItemModel->appendRow(item);
    ui->listView->setModel(ItemModel);
    f.close();

//    in.readLine();//1  除去第一行自己加入的之后代码的第一行
//    QString b = in.readLine();//2vendor_id
//    in.readLine();//3
//    in.readLine();//4
//    QString a = in.readLine();//5model name
//    in.readLine();//6
//    in.readLine();//7

//    QString c=in.readLine();//8 cpu_mhz
//    QString d= in.readLine();//9 cache size
//    in.readLine();
//    in.readLine();
//    in.readLine();
//    QString e=in.readLine();//13  cpu_cores
//    for (int i=0 ;i<95;i++)
//    {in.readLine();}//前往第109行，准备读取version文件
//    QString g = in.readLine();//110
//    ui->textEdit->setText( a+"\r\r"+b+"\r\r"+c+"\r\r"+d+"\r\r"+e+"\r\r"+ "Operating System Info: "+ g);

//    //
//    //第3个界面第56行。modules文件
//    //

//    QString row1;
//    QString row2;
//    QString row3;
//    QString line;
//    int     firstblank;
//    int     secondblank;
//    int     thirdblank;
//    int     w;
//   for(w=0;w<flag;w++)
//   {
//   ui->tableWidget_2->removeRow(flag);
//   }

//    while(!(line=="wangzhengqi"))
//    {
//        line=in.readLine();
//    }

//    line=in.readLine();//111行
//    line=in.readLine();//112行
//    w=0;
//    while(!(line == "wanghao"))
//    {

//        firstblank=line.indexOf(" ");
//        row1=line.mid(0,firstblank);
//        secondblank=line.indexOf(" ",firstblank+1);
//        row2=line.mid(firstblank,secondblank-firstblank);
//        thirdblank=line.indexOf(" ",secondblank+1);
//        row3=line.mid(secondblank,thirdblank-secondblank);
//        ui->tableWidget_2->insertRow(w) ;
//        ui->tableWidget_2->setItem(w,0,new QTableWidgetItem(row1));
//        ui->tableWidget_2->setItem(w,1,new QTableWidgetItem(row2));
//        ui->tableWidget_2->setItem(w,2,new QTableWidgetItem(row3));
//        line=in.readLine();
//        w++;
//    }
//    flag=w;
//    for(w=0;w<flag;w++)
//    {
//    ui->tableWidget_2->removeRow(flag);
//    }

//     int     total1,total2;
//     int     used1,used2;
//     int     free1,free2;
//     int     k1,k2;

//     line=in.readLine();
//     line=line.right(17);//获取memtotal
//     ui->inlabel_3->setText(line);
//     k1=line.indexOf("k");
//     k1=k1-1;
//     line=line.mid(0,k1);
//     total1=line.toULong();

//     line=in.readLine();
//     line=line.right(16);//获取memfree
//     free1=line.toULong();
//     ui->inlabel_2->setText(line);

//     k1=line.indexOf("k");
//     k1=k1-1;
//     line=line.mid(0,k1);
//     free1=line.toULong();

//     for(int j=0;j<12;j++)
//     {
//         in.readLine();
//     }
//     line=in.readLine();
//     line=line.right(18);
//     ui->outlabel_3->setText(line);//获取swaptotal
//     k2=line.indexOf("k");
//     k2=k2-1;
//     line=line.mid(1,k2);//要非常注意，这里的索引应该从1开始。
//     total2=line.toULong();

//     line=in.readLine();//SWAPfree
//     line=line.right(18);
//     free2=line.toULong();
//     ui->outlabel_2->setText(line);

//     k2=line.indexOf("k");
//     k2=k2-1;
//     line=line.mid(0,k2);
//     free2=line.toULong();

//     used1=total1-free1;
//     used2=total2-free2;

//     line.setNum(used1);
//     line=line+"kB";
//     ui->inlabel_1->setText(line);
//     line.setNum(used2);
//     line=line+"kB";
//     ui->outlabel_1->setText(line);

//    //内存交换区进度条
//     unsigned long int mem,swap;
//     mem=(used1*100)/total1;
//     swap=(used2*100)/total2;
//     ui->progressBar_2->setValue(mem);
//     ui->progressBar_3->setValue(swap);

//    while(!(line=="wanghao"))//.isNull()
//    {
//       line=in.readLine();
//    }


//    int blank1,blank2,blank3,blank4,blank5,blank6,blank7;
//    QString cpu1,cpu2,cpu3,cpu4,cpu5,cpu6,cpu7;
//    int cpun1,cpun2,cpun3,cpun4,cpun5,cpun6,cpun7,used3;

//    line=in.readLine();
//    blank1=line.indexOf(" ",5);
//    blank2=line.indexOf(" ",blank1+1);
//    blank3=line.indexOf(" ",blank2+1);
//    blank4=line.indexOf(" ",blank3+1);
//    blank5=line.indexOf(" ",blank4+1);
//    blank6=line.indexOf(" ",blank5+1);
//    blank7=line.indexOf(" ",blank6+1);

//    cpu1=line.mid(5,blank1-5);
//    cpu2=line.mid(blank1,blank2-blank1);
//    cpu3=line.mid(blank2,blank3-blank2);
//    cpu4=line.mid(blank3,blank4-blank3);
//    cpu5=line.mid(blank4,blank5-blank4);
//    cpu6=line.mid(blank5,blank6-blank5);
//    cpu7=line.mid(blank6,blank7-blank6);

//    cpun1=cpu1.toULong();
//    cpun2=cpu2.toULong();
//    cpun3=cpu3.toULong();
//    cpun4=cpu4.toULong();
//    cpun5=cpu5.toULong();
//    cpun6=cpu6.toULong();
//    cpun7=cpu7.toULong();


//    used3=((cpun1+cpun2+cpun3+cpun5+cpun6+cpun7)*100)/(cpun1+cpun2+cpun3+cpun4+cpun5+cpun6+cpun7);
//    line.setNum(used3);
//    line=line+"%";
//    ui->cpulabel->setText(line);
//    ui->progressBar->setValue(used3);

//    while(!(line == "wanghao"))
//    {
//       line=in.readLine();
//    }


//    //
//    //第2个界面,是每一个进程中的stat
//    //


//        int i=2;
//        QDir qd("/proc");
//        QStringList qslist=qd.entryList();
//        QString pname,pstate,ppoi,pmem;
//        int code1,code2,code3,codep,codep2,codem,codem2;
//        QString qs=qslist[i];
//        int j;

//        while((qs[0]<='9')&&(qs[0]>='1'))
//        {
//            int n;
//            QString pid=qs;
//            qs="/proc/"+qs;
//            qs=qs+"/stat";
//            QFile f5(qs);
//            f5.open(QIODevice::ReadOnly | QIODevice::Text);
//            QString process = in.readLine();
//            code1=process.indexOf(" ");
//            code2=process.indexOf(" ",code1+1);
//            code3=process.indexOf(" ",code2+1);
//            codep=process.indexOf(" ",code3+1);

//            for(n=0;n<13;n++)
//            {
//                codep=process.indexOf(" ",codep+1);
//            }

//            codep2=process.indexOf(" ",codep+1);
//            codem=process.indexOf(" ",codep2+1);

//            for(n=0;n<3;n++)
//            {
//                codem=process.indexOf(" ",codem+1);
//            }

//            codem2=process.indexOf(" ",codem+1);
//            pname=process.mid(code1,code2-code1);
//            pstate=process.mid(code2,code3-code2);
//            ppoi=process.mid(codep,codep2-codep);
//            pmem=process.mid(codem,codem2-codem);

//            ui->tableWidget->insertRow(0) ;
//            ui->tableWidget->setItem(0,0,new QTableWidgetItem(pid));
//            ui->tableWidget->setItem(0,1,new QTableWidgetItem(pname));
//            ui->tableWidget->setItem(0,2,new QTableWidgetItem(pstate));
//            ui->tableWidget->setItem(0,3,new QTableWidgetItem(ppoi));
//            ui->tableWidget->setItem(0,4,new QTableWidgetItem(pmem));
//            i++;
//            qs=qslist[i];
//        }
//           flag1=i-2;

//           for(j=0;j<=flag1;j++)
//           {
//           ui->tableWidget->removeRow(flag1);
//           }
}

void Widget::on_pushButton_clicked()
{
     sendMessage();
}

void Widget::on_pushButton_2_clicked()
{

    int row;
    foreach(QModelIndex index,ui->tableWidget->selectionModel()->selectedIndexes())//获取选中的行号
    {

    row=index.row();
    }

    QAbstractItemModel *lmodel=ui->tableWidget->model();
    QModelIndex lindex=lmodel->index(row,0);//获取选中的进程号，改成1就是获取进程名功能，下面相应的注释部分要取消
    QVariant datatemp =lmodel->data(lindex);
    QString pnameselected = datatemp.toString();
    /*
    int length = pnameselected.length()-3;
    qDebug() << length;
    if( pnameselected.indexOf("/")== -1 )

    {
        pnameselected=pnameselected.mid(2,length);

    }
    else{
        int end   = pnameselected.indexOf("/");
        pnameselected=pnameselected.mid(2,end-2);
        }
     */
    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);//使用数据流写入数据
    out.setVersion(QDataStream::Qt_4_6);//设置数据流的版本,客户端和服务器端使用的版本要相同
    out<<(quint16) 0;
    //out<<"process.execute(\"TASKKILL/IM "+ pnameselected + ".exe/F\");";
    out<<"kill "+pnameselected;
    out.device()->seek(0);
    out <<(quint16)(block.size()-sizeof(quint16));
    tcpServerConnection->write(block);
}


void Widget::showinfo(QModelIndex index)
{
    QString strtemp;
    strtemp=index.data().toString();

    //ui->textEdit->setText("kaishiyunxing");
    QFile f("/home/wang/BYSJ_wang_main1.1/build-tcpReceiver-Desktop_Qt_5_9_0_GCC_64bit-Debug/info_decryptor.txt");
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
