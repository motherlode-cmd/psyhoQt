#include "formsales.h"
#include "qregularexpression.h"
#include <QRegularExpression>
#include <QValidator>
#include "ui_formsales.h"

FormSales::FormSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSales)
{
    ui->setupUi(this);
    QRegularExpression numberOfPassport("\\d{4}-\\d{6}");
    QValidator *validatorPassport = new QRegularExpressionValidator(numberOfPassport, this);
    ui->lineEdit_passport->setValidator(validatorPassport);

    QRegularExpression numberOfFlight("\\d{3}-\\d{3}");
    QValidator *validatorFlight = new QRegularExpressionValidator(numberOfFlight, this);
    ui->lineEdit_flight->setValidator(validatorFlight);

    QRegularExpression numberOfTicket("\\d{9}");
    QValidator *validatorTicket = new QRegularExpressionValidator(numberOfTicket, this);
    ui->lineEdit_ticket->setValidator(validatorTicket);


}

FormSales::~FormSales()
{
    delete ui;
}

void FormSales::on_buttonBox_accepted()
{
    QStringList userData;
    userData.append(ui->lineEdit_passport->text());
    userData.append(ui->lineEdit_ticket->text());
    userData.append(ui->lineEdit_flight->text());
    emit dataEntered(userData);
    close();
}

