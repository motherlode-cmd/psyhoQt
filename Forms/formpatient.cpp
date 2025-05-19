#include "formpatient.h"
#include "ui_formpatient.h"

formpatient::formpatient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::formpatient)
{
    ui->setupUi(this);
}

formpatient::~formpatient()
{
    delete ui;
}
