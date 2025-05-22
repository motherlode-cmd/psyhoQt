#include "formcomplant.h"
#include "ui_formcomplant.h"

FormComplant::FormComplant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormComplant)
{
    ui->setupUi(this);
}

FormComplant::~FormComplant()
{
    delete ui;
}

void FormComplant::on_buttonBox_accepted()
{
    QStringList userData;
    emit dataEntered(userData);
    close();
}