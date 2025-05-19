#include "formcomplant.h"
#include "ui_formcomplant.h"

formcomplant::formcomplant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::formcomplant)
{
    ui->setupUi(this);
}

formcomplant::~formcomplant()
{
    delete ui;
}
