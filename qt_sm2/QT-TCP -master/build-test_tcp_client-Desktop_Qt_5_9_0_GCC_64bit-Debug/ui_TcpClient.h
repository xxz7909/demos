/********************************************************************************
** Form generated from reading UI file 'TcpClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QWidget *centralwidget;
    QTextEdit *teSend;
    QPushButton *btnSend;
    QTextBrowser *tbRecv;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbUser;
    QLineEdit *leUser;
    QLabel *lbIP;
    QLineEdit *leIP;
    QLabel *lbPort;
    QLineEdit *lePort;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnConnect;
    QPushButton *btnSelectFile;
    QPushButton *btnSendFile;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QStringLiteral("TcpClient"));
        TcpClient->resize(793, 447);
        centralwidget = new QWidget(TcpClient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        teSend = new QTextEdit(centralwidget);
        teSend->setObjectName(QStringLiteral("teSend"));
        teSend->setGeometry(QRect(31, 310, 611, 71));
        QFont font;
        font.setPointSize(13);
        teSend->setFont(font);
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(680, 310, 80, 39));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setFont(font);
        btnSend->setLayoutDirection(Qt::LeftToRight);
        tbRecv = new QTextBrowser(centralwidget);
        tbRecv->setObjectName(QStringLiteral("tbRecv"));
        tbRecv->setGeometry(QRect(280, 110, 361, 191));
        tbRecv->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 741, 41));
        layoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbUser = new QLabel(layoutWidget);
        lbUser->setObjectName(QStringLiteral("lbUser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbUser->sizePolicy().hasHeightForWidth());
        lbUser->setSizePolicy(sizePolicy1);
        lbUser->setFont(font);

        horizontalLayout->addWidget(lbUser);

        leUser = new QLineEdit(layoutWidget);
        leUser->setObjectName(QStringLiteral("leUser"));
        sizePolicy1.setHeightForWidth(leUser->sizePolicy().hasHeightForWidth());
        leUser->setSizePolicy(sizePolicy1);
        leUser->setFont(font);

        horizontalLayout->addWidget(leUser);

        lbIP = new QLabel(layoutWidget);
        lbIP->setObjectName(QStringLiteral("lbIP"));
        sizePolicy1.setHeightForWidth(lbIP->sizePolicy().hasHeightForWidth());
        lbIP->setSizePolicy(sizePolicy1);
        lbIP->setFont(font);

        horizontalLayout->addWidget(lbIP);

        leIP = new QLineEdit(layoutWidget);
        leIP->setObjectName(QStringLiteral("leIP"));
        sizePolicy1.setHeightForWidth(leIP->sizePolicy().hasHeightForWidth());
        leIP->setSizePolicy(sizePolicy1);
        leIP->setFont(font);

        horizontalLayout->addWidget(leIP);

        lbPort = new QLabel(layoutWidget);
        lbPort->setObjectName(QStringLiteral("lbPort"));
        sizePolicy1.setHeightForWidth(lbPort->sizePolicy().hasHeightForWidth());
        lbPort->setSizePolicy(sizePolicy1);
        lbPort->setFont(font);

        horizontalLayout->addWidget(lbPort);

        lePort = new QLineEdit(layoutWidget);
        lePort->setObjectName(QStringLiteral("lePort"));
        sizePolicy1.setHeightForWidth(lePort->sizePolicy().hasHeightForWidth());
        lePort->setSizePolicy(sizePolicy1);
        lePort->setFont(font);

        horizontalLayout->addWidget(lePort);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        sizePolicy1.setHeightForWidth(btnConnect->sizePolicy().hasHeightForWidth());
        btnConnect->setSizePolicy(sizePolicy1);
        btnConnect->setFont(font);

        horizontalLayout->addWidget(btnConnect);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 4);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 2);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 1);
        btnSelectFile = new QPushButton(centralwidget);
        btnSelectFile->setObjectName(QStringLiteral("btnSelectFile"));
        btnSelectFile->setGeometry(QRect(670, 110, 90, 40));
        btnSelectFile->setFont(font);
        btnSendFile = new QPushButton(centralwidget);
        btnSendFile->setObjectName(QStringLiteral("btnSendFile"));
        btnSendFile->setGeometry(QRect(670, 180, 90, 40));
        btnSendFile->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 110, 241, 191));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 111, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 90, 111, 17));
        TcpClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TcpClient);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 793, 28));
        TcpClient->setMenuBar(menubar);
        statusbar = new QStatusBar(TcpClient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TcpClient->setStatusBar(statusbar);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QMainWindow *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "MainWindow", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TcpClient", "\345\217\221\351\200\201", Q_NULLPTR));
        lbUser->setText(QApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        leUser->setText(QApplication::translate("TcpClient", "PART1", Q_NULLPTR));
        lbIP->setText(QApplication::translate("TcpClient", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        leIP->setText(QApplication::translate("TcpClient", "127.0.0.1", Q_NULLPTR));
        lbPort->setText(QApplication::translate("TcpClient", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        lePort->setText(QApplication::translate("TcpClient", "6666", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("TcpClient", "\350\277\236\346\216\245", Q_NULLPTR));
        btnSelectFile->setText(QApplication::translate("TcpClient", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        btnSendFile->setText(QApplication::translate("TcpClient", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("TcpClient", "\345\217\221\351\200\201\346\226\207\344\273\266\347\232\204\345\206\205\345\256\271:", Q_NULLPTR));
        label_2->setText(QApplication::translate("TcpClient", "\345\216\206\345\217\262\345\210\227\350\241\250:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
