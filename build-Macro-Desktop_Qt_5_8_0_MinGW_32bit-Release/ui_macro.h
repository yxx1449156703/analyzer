/********************************************************************************
** Form generated from reading UI file 'macro.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACRO_H
#define UI_MACRO_H

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

class Ui_Macro
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Macro)
    {
        if (Macro->objectName().isEmpty())
            Macro->setObjectName(QStringLiteral("Macro"));
        Macro->resize(900, 600);
        Macro->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/image.png);"));
        centralWidget = new QWidget(Macro);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 130, 101, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 197, 81, 21));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(130, 0, 301, 261));
        textEdit->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/white.png);"));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(570, 0, 301, 261));
        textEdit_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/white.png);"));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(130, 270, 301, 261));
        textEdit_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/white.png);"));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(570, 270, 301, 261));
        textEdit_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/white.png);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 81, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 60, 81, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 360, 111, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(450, 360, 111, 31));
        label_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/back.png);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 440, 101, 28));
        Macro->setCentralWidget(centralWidget);
        textEdit->raise();
        label_4->raise();
        pushButton->raise();
        pushButton_2->raise();
        textEdit_2->raise();
        textEdit_3->raise();
        textEdit_4->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        pushButton_3->raise();
        menuBar = new QMenuBar(Macro);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 26));
        Macro->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Macro);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Macro->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Macro);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Macro->setStatusBar(statusBar);

        retranslateUi(Macro);

        QMetaObject::connectSlotsByName(Macro);
    } // setupUi

    void retranslateUi(QMainWindow *Macro)
    {
        Macro->setWindowTitle(QApplication::translate("Macro", "Macro", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Macro", "\351\200\211\346\213\251\346\226\207\344\273\266\345\257\274\345\205\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Macro", "\347\241\256\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("Macro", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\276\223\345\205\245\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Macro", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\270\211\345\234\260\345\235\200\347\240\201\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Macro", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\257\215\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Macro", "<html><head/><body><p><span style=\" font-size:10pt;\">\350\257\255\346\263\225\345\210\206\346\236\220\347\273\223\346\236\234\357\274\232</span></p></body></html>", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Macro", "\346\211\223\345\274\200\346\226\207\344\273\266\344\275\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Macro: public Ui_Macro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACRO_H
