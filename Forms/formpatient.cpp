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
