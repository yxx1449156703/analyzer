/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(400, 254);
        pushButton = new QPushButton(Dialog1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 210, 93, 28));
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 210, 93, 28));
        label = new QLabel(Dialog1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 101, 31));
        label_2 = new QLabel(Dialog1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 170, 231, 21));
        textEdit = new QTextEdit(Dialog1);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(43, 70, 331, 91));

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog1", "\347\273\210\346\255\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog1", "\347\273\255\347\274\226\350\257\221", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog1", "<html><head/><body><p><span style=\" font-size:12pt; color:#ff0000;\">\357\274\201</span><span style=\" font-size:12pt;\">\351\224\231\350\257\257\344\277\241\346\201\257</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog1", "\350\257\267\346\243\200\346\237\245\350\276\223\345\205\245\344\270\255\347\272\242\350\211\262\346\240\207\350\257\206\345\244\204\346\230\257\345\220\246\346\255\243\347\241\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
