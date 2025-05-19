#include "formprescription.h"
#include "ui_formprescription.h"

formprescription::formprescription(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::formprescription)
{
    ui->setupUi(this);
}

formprescription::~formprescription()
{
    delete ui;
}
