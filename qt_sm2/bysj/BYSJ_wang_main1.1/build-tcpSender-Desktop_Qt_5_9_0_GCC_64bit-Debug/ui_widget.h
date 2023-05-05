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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *clientStatusLabel;
    QLabel *label;
    QLineEdit *hostLineEdit;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QPushButton *sendButton;
    QLineEdit *lineEdit;
    QPushButton *sendButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_miwen;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(620, 425);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 211, 411));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        clientStatusLabel = new QLabel(widget);
        clientStatusLabel->setObjectName(QStringLiteral("clientStatusLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223"));
        font.setPointSize(7);
        clientStatusLabel->setFont(font);
        clientStatusLabel->setFrameShape(QFrame::StyledPanel);
        clientStatusLabel->setTextFormat(Qt::PlainText);

        verticalLayout->addWidget(clientStatusLabel);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223"));
        font1.setPointSize(8);
        font1.setUnderline(true);
        label->setFont(font1);
        label->setFrameShape(QFrame::Panel);

        verticalLayout->addWidget(label);

        hostLineEdit = new QLineEdit(widget);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        QFont font2;
        font2.setFamily(QStringLiteral("Abyssinica SIL"));
        font2.setPointSize(24);
        hostLineEdit->setFont(font2);

        verticalLayout->addWidget(hostLineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223"));
        font3.setPointSize(9);
        font3.setUnderline(true);
        label_2->setFont(font3);
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(label_2);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        QFont font4;
        font4.setFamily(QStringLiteral("Abyssinica SIL"));
        font4.setPointSize(26);
        portLineEdit->setFont(font4);

        verticalLayout->addWidget(portLineEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setFont(font2);

        verticalLayout->addWidget(sendButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font4);

        verticalLayout->addWidget(lineEdit);

        sendButton_2 = new QPushButton(widget);
        sendButton_2->setObjectName(QStringLiteral("sendButton_2"));
        sendButton_2->setFont(font2);

        verticalLayout->addWidget(sendButton_2);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(220, 10, 181, 401));
        textEdit_miwen = new QTextEdit(Widget);
        textEdit_miwen->setObjectName(QStringLiteral("textEdit_miwen"));
        textEdit_miwen->setGeometry(QRect(420, 10, 181, 401));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\350\212\202\347\202\271", Q_NULLPTR));
        clientStatusLabel->setText(QApplication::translate("Widget", "\347\212\266\346\200\201\357\274\232\347\255\211\345\276\205\350\277\236\346\216\245", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\255\345\277\203\345\234\260\345\235\200", Q_NULLPTR));
        hostLineEdit->setText(QApplication::translate("Widget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", Q_NULLPTR));
        portLineEdit->setText(QApplication::translate("Widget", "99999", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\344\270\255\345\277\203", Q_NULLPTR));
        lineEdit->setText(QString());
        sendButton_2->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
