#include "formpassanger.h"
#include "ui_formpassanger.h"
#include <iostream>


FormPassanger::FormPassanger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPassanger)
{
    ui->setupUi(this);
    QRegularExpression numberOfPassport("\\d{4}-\\d{6}");
    QValidator *validatorPassport = new QRegularExpressionValidator(numberOfPassport, this);
    ui->lineEdit_passport_num->setValidator(validatorPassport);

}

FormPassanger::~FormPassanger()
{
    delete ui;
}

void FormPassanger::on_buttonBox_accepted()
{
    QStringList userData;
    userData.append(ui->lineEdit_passport_num->text());
    userData.append(ui->lineEdit_date_passport->text());
    userData.append(ui->lineEdit_fio->text());
    userData.append(ui->dateEdit->text());
    //std::cout<< userData.at(3).toStdString() <<std::endl;
    emit dataEntered(userData);
    close();
}

