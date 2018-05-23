#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include "dialog1.h"

namespace Ui {
class dialog;
}

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

signals:
    void  sendData(QString);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void dcolor(QString number);
    void on_pushButton_4_windowIconTextChanged(const QString &iconText);

private:
    Ui::dialog *ui;
    Dialog1 *dialog1;
};

#endif // DIALOG_H
