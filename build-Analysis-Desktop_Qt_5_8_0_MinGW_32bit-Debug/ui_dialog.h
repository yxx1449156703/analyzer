/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QStringLiteral("dialog"));
        dialog->resize(933, 641);
        centralWidget = new QWidget(dialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 20, 321, 231));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(580, 20, 321, 231));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(130, 300, 321, 231));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(580, 300, 321, 231));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 81, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 101, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 170, 71, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 120, 81, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 390, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 390, 111, 20));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(430, 550, 131, 28));
        dialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 933, 26));
        dialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dialog->setStatusBar(statusBar);

        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QMainWindow *dialog)
    {
        dialog->setWindowTitle(QApplication::translate("dialog", "dialog", Q_NULLPTR));
        label->setText(QApplication::translate("dialog", "\350\276\223\345\205\245\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("dialog", "\351\200\211\346\213\251\346\226\207\344\273\266\345\257\274\345\205\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("dialog", "\347\241\256\350\256\244", Q_NULLPTR));
        label_2->setText(QApplication::translate("dialog", "\344\270\211\345\234\260\345\235\200\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("dialog", "\350\257\215\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("dialog", "\350\257\255\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("dialog", "\346\237\245\347\234\213\346\226\207\344\273\266\346\211\200\345\234\250\350\267\257\345\276\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
