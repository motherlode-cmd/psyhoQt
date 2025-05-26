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

    userData.append(ui->lineEdit_full_name->text());
    userData.append(ui->lineEdit_email->text());
    userData.append(ui->lineEdit_speciality->text());
    userData.append(ui->lineEdit_phone->text());
    emit dataEntered(userData);
    close();
}