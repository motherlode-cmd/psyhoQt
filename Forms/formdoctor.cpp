#include "formdoctor.h"
#include "ui_formdoctor.h"

FormDoctor::FormDoctor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormDoctor)
{
    ui->setupUi(this);
}

FormDoctor::~FormDoctor()
{
    delete ui;
}

void FormDoctor::on_buttonBox_accepted()
{
    QStringList userData;
    emit dataEntered(userData);
    close();
}