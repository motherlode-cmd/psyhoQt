#include "formpatient.h"
#include "ui_formpatient.h"

FormPatient::FormPatient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormPatient)
{
    ui->setupUi(this);
}

FormPatient::~FormPatient()
{
    delete ui;
}

void FormPatient::on_buttonBox_accepted()
{
    QStringList userData;
    emit dataEntered(userData);
    close();
}