#include "formflight.h"
#include "ui_formflight.h"

FormFlight::FormFlight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFlight)
{
    ui->setupUi(this);
    QRegularExpression numberOfFlight("\\d{3}-\\d{3}");
    QValidator *validator = new QRegularExpressionValidator(numberOfFlight, this);
    ui->lineEdit_num_flight->setValidator(validator);
}

FormFlight::~FormFlight()
{
    delete ui;
}

void FormFlight::on_buttonBox_accepted()
{
    QStringList userData;
    userData.append(ui->lineEdit_num_flight->text());
    userData.append(ui->lineEdit_to_port->text());
    userData.append(ui->lineEdit_from_port->text());
    userData.append(ui->lineEdit_name_company->text());
    userData.append(ui->dateEdit->text());
    userData.append(ui->timeEdit->text());
    userData.append(ui->spinBox_seats->text());
    userData.append(ui->spinBox_2->text());
    emit dataEntered(userData);
    close();
}

