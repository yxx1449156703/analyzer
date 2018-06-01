#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
}

Warning::~Warning()
{
    delete ui;
}

void Warning::on_pushButton_clicked()
{
    this->close();
}

void Warning::receiveData(QString da)
{
    ui->textEdit->setText(da);
}
