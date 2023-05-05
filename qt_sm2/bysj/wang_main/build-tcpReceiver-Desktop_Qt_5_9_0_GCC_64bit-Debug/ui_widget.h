/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTreeView *treeView;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *serverStatusLabel;
    QProgressBar *serverProgressBar;
    QLineEdit *port;
    QPushButton *startButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_2;
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
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QProgressBar *progressBar_3;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QProgressBar *progressBar_2;
    QWidget *page_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(947, 532);
        treeView = new QTreeView(Widget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(9, 15, 141, 511));
        toolBox = new QToolBox(Widget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(161, 15, 781, 481));
        toolBox->setFrameShape(QFrame::StyledPanel);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 779, 368));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        serverStatusLabel = new QLabel(widget);
        serverStatusLabel->setObjectName(QStringLiteral("serverStatusLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223"));
        font.setPointSize(28);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(serverStatusLabel);

        serverProgressBar = new QProgressBar(widget);
        serverProgressBar->setObjectName(QStringLiteral("serverProgressBar"));
        serverProgressBar->setValue(0);

        verticalLayout->addWidget(serverProgressBar);

        port = new QLineEdit(widget);
        port->setObjectName(QStringLiteral("port"));

        verticalLayout->addWidget(port);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout->addWidget(startButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("\345\273\272\347\253\213\350\277\236\346\216\245"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 779, 368));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 0, 681, 361));
        tabWidget->setAcceptDrops(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 0, 661, 321));
        tabWidget->addTab(tab, QString());
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
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
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
        widget1 = new QWidget(tab_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(11, 208, 341, 27));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        progressBar_3 = new QProgressBar(widget1);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setValue(0);

        horizontalLayout->addWidget(progressBar_3);

        widget2 = new QWidget(tab_3);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 131, 341, 27));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        progressBar_2 = new QProgressBar(widget2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(0);

        horizontalLayout_3->addWidget(progressBar_2);

        tabWidget->addTab(tab_3, QString());
        toolBox->addItem(page_2, QString::fromUtf8("\347\233\221\346\216\247\346\250\241\345\235\227"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 779, 368));
        toolBox->addItem(page_3, QString::fromUtf8("\345\257\206\351\222\245\345\210\206\345\217\221\346\250\241\345\235\227"));

        retranslateUi(Widget);

        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\270\255\345\277\203", Q_NULLPTR));
        serverStatusLabel->setText(QApplication::translate("Widget", "\347\255\211\345\276\205\347\233\221\345\220\254\343\200\202\343\200\202", Q_NULLPTR));
        port->setText(QApplication::translate("Widget", "99999", Q_NULLPTR));
        port->setPlaceholderText(QApplication::translate("Widget", "\347\253\257\345\217\243", Q_NULLPTR));
        startButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\345\273\272\347\253\213\350\277\236\346\216\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\263\273\347\273\237\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "PID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "\344\274\230\345\205\210\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\345\215\240\347\224\250\345\206\205\345\255\230", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\346\235\200\346\216\211\346\255\244\350\277\233\347\250\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\350\277\233\347\250\213\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "\346\250\241\345\235\227\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "\345\215\240\347\224\250\345\206\205\345\255\230", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "\344\275\277\347\224\250\346\254\241\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Widget", "\346\250\241\345\235\227\344\277\241\346\201\257", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "\345\215\240\347\224\250\347\216\207\357\274\232", Q_NULLPTR));
        outlabel_2->setText(QString());
        label_22->setText(QApplication::translate("Widget", "\345\205\261", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "\345\267\262\347\224\250", Q_NULLPTR));
        label_20->setText(QApplication::translate("Widget", "\345\267\262\347\224\250", Q_NULLPTR));
        inlabel_2->setText(QString());
        inlabel_1->setText(QString());
        label_8->setText(QApplication::translate("Widget", "CPU\345\215\240\347\224\250", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "\345\211\251\344\275\231", Q_NULLPTR));
        inlabel_3->setText(QString());
        label_16->setText(QApplication::translate("Widget", "\345\205\261", Q_NULLPTR));
        cpulabel->setText(QString());
        outlabel_3->setText(QString());
        outlabel_1->setText(QString());
        label_21->setText(QApplication::translate("Widget", "\345\211\251\344\275\231", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\345\206\205\345\255\230\345\222\214\344\272\244\346\215\242\345\210\206\345\214\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\344\272\244\346\215\242", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\345\206\205\345\255\230", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\350\265\204\346\272\220\344\277\241\346\201\257", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Widget", "\347\233\221\346\216\247\346\250\241\345\235\227", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Widget", "\345\257\206\351\222\245\345\210\206\345\217\221\346\250\241\345\235\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
