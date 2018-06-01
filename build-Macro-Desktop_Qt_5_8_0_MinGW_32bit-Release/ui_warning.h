/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

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

class Ui_Warning
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *Warning)
    {
        if (Warning->objectName().isEmpty())
            Warning->setObjectName(QStringLiteral("Warning"));
        Warning->resize(400, 300);
        Warning->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/warn.png);"));
        label = new QLabel(Warning);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 211, 41));
        label_2 = new QLabel(Warning);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 210, 341, 16));
        pushButton = new QPushButton(Warning);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 260, 93, 28));
        textEdit = new QTextEdit(Warning);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 60, 281, 121));
        textEdit->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/bai.png);"));

        retranslateUi(Warning);

        QMetaObject::connectSlotsByName(Warning);
    } // setupUi

    void retranslateUi(QDialog *Warning)
    {
        Warning->setWindowTitle(QApplication::translate("Warning", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Warning", "<html><head/><body><p><span style=\" font-size:14pt; color:#ff0000;\">(\342\212\231x\342\212\231)\351\224\231\350\257\257\344\277\241\346\201\257</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Warning", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\257\267\346\243\200\346\237\245\347\272\242\350\211\262\346\240\207\350\257\206\345\244\204\346\230\257\345\220\246\350\276\223\345\205\245\346\255\243\347\241\256(\342\227\217\313\207\342\210\200\313\207\342\227\217)</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Warning", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Warning: public Ui_Warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
