#include "formtreatment.h"
#include "ui_formtreatment.h"

FormTreatment::FormTreatment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormTreatment)
{
    ui->setupUi(this);
}

FormTreatment::~FormTreatment()
{
    delete ui;
}
