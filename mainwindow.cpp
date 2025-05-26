#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtModels/QTableModel.h"
#include <iostream>
#include <QDebug>
#include "Forms/formdoctor.h"
#include "Forms/formcomplant.h"
#include "Forms/formpatient.h"
#include "Forms/formprescription.h"
#include "Forms/formtreatment.h"
#include <yaml-cpp/yaml.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // this->log_in_postgres();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./psyho.db");

    if (db.open())
    {
        qDebug("opened");
    }
    else
    {
        qDebug("not opened");
    }

    DoctorListModel = new QtModel(this, ElementType::Doctor);
    PatientListModel = new QtModel(this, ElementType::Patient);
    PrescriotionListModel = new QtModel(this, ElementType::Prescriotion);
    TreatmentListModel = new QtModel(this, ElementType::Treatment);
    ComplantListModel = new QtModel(this, ElementType::Complant);

    ui->comboBox->addItem("Complant");
    ui->comboBox->addItem("Doctor");
    ui->comboBox->addItem("Patient");
    ui->comboBox->addItem("Prescriotion");
    ui->comboBox->addItem("Treatment");

    this->ui->table->setModel(ComplantListModel);
    ui->table->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->table->setModel(ComplantListModel);
    }
    else if (index == 1)
    {
        ui->table->setModel(DoctorListModel);
    }
    else if (index == 2)
    {
        ui->table->setModel(PatientListModel);
    }
    else if (index == 3)
    {
        ui->table->setModel(PrescriotionListModel);
    }
    else if (index == 4)
    {
        ui->table->setModel(TreatmentListModel);
    }
}

void MainWindow::addDoctor(QStringList &list)
{
    DoctorListModel->addItem(list);
}

void MainWindow::addPatient(QStringList &list)
{
    PatientListModel->addItem(list);
}

void MainWindow::addPrescriotion(QStringList &list)
{
    PrescriotionListModel->addItem(list);
}

void MainWindow::addTreatment(QStringList &list)
{
    TreatmentListModel->addItem(list);
}

void MainWindow::addComplant(QStringList &list)
{
    ComplantListModel->addItem(list);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->comboBox->currentIndex() == 0)
    {
        FormComplant *form = new FormComplant();
        connect(form, &FormComplant::dataEntered, this, &MainWindow::addComplant);
        form->show();
    }
    else if (ui->comboBox->currentIndex() == 1)
    {
        FormDoctor *form = new FormDoctor();
        connect(form, &FormDoctor::dataEntered, this, &MainWindow::addDoctor);
        form->show();
    }
    else if (ui->comboBox->currentIndex() == 2)
    {
        FormPatient *form = new FormPatient();
        connect(form, &FormPatient::dataEntered, this, &MainWindow::addPatient);
        form->show();
    }
    else if (ui->comboBox->currentIndex() == 3)
    {
        FormPrescription *form = new FormPrescription();
        connect(form, &FormPrescription::dataEntered, this, &MainWindow::addPrescriotion);
        form->show();
    }
    else if (ui->comboBox->currentIndex() == 4)
    {
        FormTreatment *form = new FormTreatment();
        connect(form, &FormTreatment::dataEntered, this, &MainWindow::addTreatment);
        form->show();
    }
}

void MainWindow::on_pushButton_search_clicked()
{
    // search_setup(true);
    // if(ui->comboBox->currentIndex() == 0) {
    //     ui->radioButton->setText("Поиск пассажира по ФИО");
    //     ui->radioButton_2->setText("Поиск пассажира по пасспорту");
    // } else if(ui->comboBox->currentIndex() == 1) {
    //     ui->radioButton->setText("Поиск авиарейса по номеру");
    //     ui->radioButton_2->setText("Поиск авиарейса по названию аэропорта");
    // }
}

void MainWindow::search_setup(bool setup)
{
    // serup == true -> поиск идет
    //  ui->pushButton_search->setEnabled(!setup);
    //  ui->pushButton_delete->setEnabled(!setup);
    //  ui->pushButton->setEnabled(!setup);
    //  ui->pushButton_ok->setEnabled(setup);
    //  ui->pushButton_ok->setVisible(setup);
    //  ui->lineEdit_search->setVisible(setup);
    //  ui->lineEdit_search->setEnabled(setup);
    //  ui->radioButton->setVisible(setup);
    //  ui->radioButton_2->setVisible(setup);
    //  ui->radioButton->setEnabled(setup);
    //  ui->radioButton_2->setEnabled(setup);
    //  ui->comboBox->setEnabled(!setup);
}

void MainWindow::on_pushButton_ok_clicked()
{
    search_setup(false);
}

void MainWindow::on_lineEdit_search_textEdited(const QString &arg1)
{
    // if(ui->comboBox->currentIndex() == 0) {
    //     if(ui->radioButton_2->isChecked())
    //         passangerHashTableModel->search(arg1);
    //     else if(ui->radioButton->isChecked())
    //         passangerHashTableModel->alt_search(arg1);
    // } else if(ui->comboBox->currentIndex() == 1) {
    //     if(ui->radioButton->isChecked())
    //         flightAVLTreeModel->search(arg1);
    //     if(ui->radioButton_2->isChecked())
    //         flightAVLTreeModel->alt_search(arg1);
    // }
}

void MainWindow::on_pushButton_delete_clicked()
{
    QModelIndexList indexes = ui->table->selectionModel()->selectedRows();
    if (!indexes.isEmpty())
    {
        QModelIndex index = indexes.first();

        if (ui->comboBox->currentIndex() == 0)
        {
            ComplantListModel->removeItem(index);
        }
        else if (ui->comboBox->currentIndex() == 1)
        {
            DoctorListModel->removeItem(index);
        }
        else if (ui->comboBox->currentIndex() == 2)
        {
            PatientListModel->removeItem(index);
        }
        else if (ui->comboBox->currentIndex() == 3)
        {
            PrescriotionListModel->removeItem(index);
        }
        else if (ui->comboBox->currentIndex() == 4)
        {
            TreatmentListModel->removeItem(index);
        }
    }
}

void MainWindow::log_in_postgres()
{
    try
    {
        YAML::Node config = YAML::LoadFile("postgres_log.yaml");

        // Пример доступа к данным
        QString username = QString::fromStdString(config["username"].as<std::string>());
        QString password = QString::fromStdString(config["password"].as<std::string>());
        QString database_name = QString::fromStdString(config["database_name"].as<std::string>());
        QString host_name = QString::fromStdString(config["host_name"].as<std::string>());
        int port_num = config["port_num"].as<int>();

        // db.setDatabaseName(database_name);
        // if (db.open()) {
        //     qDebug("opened");
        // } else {
        //    qDebug("not opened");
        // }
        // db.setHostName(host_name);
        // db.setPort(port_num);
        // db.setUserName(username);
        // db.setPassword(password);
    }
    catch (const YAML::Exception &e)
    {
        std::cerr << "Ошибка чтения YAML: " << e.what() << std::endl;
    }
}