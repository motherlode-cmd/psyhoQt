#include "formprescription.h"
#include "ui_formprescription.h"

FormPrescription::FormPrescription(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormPrescription)
{
    ui->setupUi(this);
}

FormPrescription::~FormPrescription()
{
    delete ui;
}
