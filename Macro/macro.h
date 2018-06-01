#ifndef MACRO_H
#define MACRO_H

#include <QMainWindow>
#include "warning.h"

namespace Ui {
class Macro;
}

class Macro : public QMainWindow
{
    Q_OBJECT

public:
    explicit Macro(QWidget *parent = 0);
    ~Macro();

signals:
    void  sendData(QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Macro *ui;
    Warning *warning;
};

#endif // MACRO_H
