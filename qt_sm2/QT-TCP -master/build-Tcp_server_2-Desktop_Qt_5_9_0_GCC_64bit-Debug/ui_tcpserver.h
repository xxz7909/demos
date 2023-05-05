/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcpserver
{
public:
    QListView *listView;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QWidget *widget;
    QPushButton *btnSendFile;
    QPushButton *btnSelectFile;
    QTextBrowser *tbRecv;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lePort;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClearMsg;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnListen;
    QPushButton *btnSend;
    QTextEdit *teSend;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_3;
    QLabel *label_12;
    QProgressBar *progressBar;
    QLabel *outlabel_2;
    QLabel *label_22;
    QLabel *label_14;
    QLabel *label_20;
    QLabel *inlabel_2;
    QLabel *inlabel_1;
    QLabel *label_8;
    QLabel *label_15;
    QLabel *inlabel_3;
    QLabel *label_16;
    QLabel *cpulabel;
    QLabel *outlabel_3;
    QLabel *outlabel_1;
    QLabel *label_21;
    QLabel *label_11;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QProgressBar *progressBar_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QProgressBar *progressBar_2;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_2;
    QWidget *tab_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Tcpserver)
    {
        if (Tcpserver->objectName().isEmpty())
            Tcpserver->setObjectName(QStringLiteral("Tcpserver"));
        Tcpserver->resize(919, 551);
        Tcpserver->setMouseTracking(false);
        Tcpserver->setLayoutDirection(Qt::LeftToRight);
        listView = new QListView(Tcpserver);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 21, 171, 531));
        tabWidget = new QTabWidget(Tcpserver);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(170, 20, 741, 531));
        tabWidget->setAcceptDrops(false);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        widget = new QWidget(tab_6);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 709, 402));
        btnSendFile = new QPushButton(widget);
        btnSendFile->setObjectName(QStringLiteral("btnSendFile"));
        btnSendFile->setGeometry(QRect(571, 160, 90, 40));
        QFont font;
        font.setPointSize(13);
        btnSendFile->setFont(font);
        btnSelectFile = new QPushButton(widget);
        btnSelectFile->setObjectName(QStringLiteral("btnSelectFile"));
        btnSelectFile->setGeometry(QRect(571, 110, 90, 40));
        btnSelectFile->setFont(font);
        tbRecv = new QTextBrowser(widget);
        tbRecv->setObjectName(QStringLiteral("tbRecv"));
        tbRecv->setGeometry(QRect(21, 80, 531, 181));
        tbRecv->setFont(font);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 19, 611, 41));
        layoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lePort = new QLineEdit(layoutWidget);
        lePort->setObjectName(QStringLiteral("lePort"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lePort->sizePolicy().hasHeightForWidth());
        lePort->setSizePolicy(sizePolicy1);
        lePort->setFont(font);

        horizontalLayout->addWidget(lePort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClearMsg = new QPushButton(layoutWidget);
        btnClearMsg->setObjectName(QStringLiteral("btnClearMsg"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnClearMsg->sizePolicy().hasHeightForWidth());
        btnClearMsg->setSizePolicy(sizePolicy2);
        btnClearMsg->setFont(font);

        horizontalLayout->addWidget(btnClearMsg);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnListen = new QPushButton(layoutWidget);
        btnListen->setObjectName(QStringLiteral("btnListen"));
        btnListen->setFont(font);

        horizontalLayout->addWidget(btnListen);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 3);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 2);
        btnSend = new QPushButton(widget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(591, 280, 61, 31));
        sizePolicy2.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy2);
        btnSend->setFont(font);
        teSend = new QTextEdit(widget);
        teSend->setObjectName(QStringLiteral("teSend"));
        teSend->setGeometry(QRect(20, 270, 531, 51));
        teSend->setFont(font);
        tabWidget->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 0, 661, 321));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(84, 40, 60, 23));
        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(84, 9, 251, 25));
        progressBar->setValue(0);
        outlabel_2 = new QLabel(tab_3);
        outlabel_2->setObjectName(QStringLiteral("outlabel_2"));
        outlabel_2->setGeometry(QRect(195, 240, 121, 20));
        outlabel_2->setFrameShape(QFrame::Panel);
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(332, 240, 16, 23));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 170, 30, 23));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(12, 240, 30, 23));
        inlabel_2 = new QLabel(tab_3);
        inlabel_2->setObjectName(QStringLiteral("inlabel_2"));
        inlabel_2->setGeometry(QRect(195, 170, 121, 20));
        inlabel_2->setFrameShape(QFrame::Box);
        inlabel_1 = new QLabel(tab_3);
        inlabel_1->setObjectName(QStringLiteral("inlabel_1"));
        inlabel_1->setGeometry(QRect(55, 170, 101, 20));
        inlabel_1->setFrameShape(QFrame::Box);
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(9, 9, 69, 25));
        label_8->setFrameShape(QFrame::StyledPanel);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(160, 170, 30, 23));
        inlabel_3 = new QLabel(tab_3);
        inlabel_3->setObjectName(QStringLiteral("inlabel_3"));
        inlabel_3->setGeometry(QRect(350, 170, 121, 19));
        inlabel_3->setFrameShape(QFrame::Box);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(330, 170, 16, 23));
        cpulabel = new QLabel(tab_3);
        cpulabel->setObjectName(QStringLiteral("cpulabel"));
        cpulabel->setGeometry(QRect(150, 40, 61, 19));
        cpulabel->setFrameShape(QFrame::Box);
        outlabel_3 = new QLabel(tab_3);
        outlabel_3->setObjectName(QStringLiteral("outlabel_3"));
        outlabel_3->setGeometry(QRect(350, 240, 121, 20));
        outlabel_3->setFrameShape(QFrame::Box);
        outlabel_1 = new QLabel(tab_3);
        outlabel_1->setObjectName(QStringLiteral("outlabel_1"));
        outlabel_1->setGeometry(QRect(55, 240, 101, 20));
        outlabel_1->setFrameShape(QFrame::Box);
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(157, 240, 30, 23));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(9, 90, 115, 25));
        label_11->setFrameShape(QFrame::StyledPanel);
        layoutWidget_3 = new QWidget(tab_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(11, 208, 341, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        progressBar_3 = new QProgressBar(layoutWidget_3);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setValue(0);

        horizontalLayout_2->addWidget(progressBar_3);

        layoutWidget_4 = new QWidget(tab_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 131, 341, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        progressBar_2 = new QProgressBar(layoutWidget_4);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(0);

        horizontalLayout_3->addWidget(progressBar_2);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(9, 9, 571, 311));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 50, 83, 31));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_2 = new QTableWidget(tab_4);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_3->addWidget(tableWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        layoutWidget1 = new QWidget(tab_5);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 0, 651, 411));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget1);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        tabWidget->addTab(tab_5, QString());

        retranslateUi(Tcpserver);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Tcpserver);
    } // setupUi

    void retranslateUi(QWidget *Tcpserver)
    {
        Tcpserver->setWindowTitle(QApplication::translate("Tcpserver", "TCPServer", Q_NULLPTR));
        btnSendFile->setText(QApplication::translate("Tcpserver", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        btnSelectFile->setText(QApplication::translate("Tcpserver", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("Tcpserver", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lePort->setText(QApplication::translate("Tcpserver", "6666", Q_NULLPTR));
        btnClearMsg->setText(QApplication::translate("Tcpserver", "\346\270\205\347\251\272\346\266\210\346\201\257", Q_NULLPTR));
        btnListen->setText(QApplication::translate("Tcpserver", "\344\276\246\345\220\254", Q_NULLPTR));
        btnSend->setText(QApplication::translate("Tcpserver", "\345\217\221\351\200\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Tcpserver", "\345\274\200\345\247\213\344\276\246\345\220\254", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Tcpserver", "\347\263\273\347\273\237\344\277\241\346\201\257", Q_NULLPTR));
        label_12->setText(QApplication::translate("Tcpserver", "\345\215\240\347\224\250\347\216\207\357\274\232", Q_NULLPTR));
        outlabel_2->setText(QString());
        label_22->setText(QApplication::translate("Tcpserver", "\345\205\261", Q_NULLPTR));
        label_14->setText(QApplication::translate("Tcpserver", "\345\267\262\347\224\250", Q_NULLPTR));
        label_20->setText(QApplication::translate("Tcpserver", "\345\267\262\347\224\250", Q_NULLPTR));
        inlabel_2->setText(QString());
        inlabel_1->setText(QString());
        label_8->setText(QApplication::translate("Tcpserver", "CPU\345\215\240\347\224\250", Q_NULLPTR));
        label_15->setText(QApplication::translate("Tcpserver", "\345\211\251\344\275\231", Q_NULLPTR));
        inlabel_3->setText(QString());
        label_16->setText(QApplication::translate("Tcpserver", "\345\205\261", Q_NULLPTR));
        cpulabel->setText(QString());
        outlabel_3->setText(QString());
        outlabel_1->setText(QString());
        label_21->setText(QApplication::translate("Tcpserver", "\345\211\251\344\275\231", Q_NULLPTR));
        label_11->setText(QApplication::translate("Tcpserver", "\345\206\205\345\255\230\345\222\214\344\272\244\346\215\242\345\210\206\345\214\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("Tcpserver", "\344\272\244\346\215\242", Q_NULLPTR));
        label_9->setText(QApplication::translate("Tcpserver", "\345\206\205\345\255\230", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Tcpserver", "\350\265\204\346\272\220\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Tcpserver", "PID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Tcpserver", "\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Tcpserver", "\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Tcpserver", "\344\274\230\345\205\210\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Tcpserver", "\345\215\240\347\224\250\345\206\205\345\255\230", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Tcpserver", "\346\235\200\346\216\211\346\255\244\350\277\233\347\250\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Tcpserver", "\350\277\233\347\250\213\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("Tcpserver", "\346\250\241\345\235\227\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("Tcpserver", "\345\215\240\347\224\250\345\206\205\345\255\230", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("Tcpserver", "\344\275\277\347\224\250\346\254\241\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Tcpserver", "\346\250\241\345\235\227\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Tcpserver", "\350\277\234\347\250\213 shell", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tcpserver: public Ui_Tcpserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
