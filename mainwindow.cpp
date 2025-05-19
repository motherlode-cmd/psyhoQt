#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtModels/QTableModel.h"
#include <iostream>
#include "Forms/formsales.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Билеты");
    ui->comboBox->addItem("Doctor");
    ui->comboBox->addItem("Patient");
    ui->comboBox->addItem("Prescriotion");
    ui->comboBox->addItem("Treatment");
    ui->comboBox->addItem("Complant");
    search_setup(false);
    this->ui->table->setModel(salesListModel);
    ui->table->resizeColumnsToContents();
    ui->pushButton_search->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0) {
         ui->table->setModel(salesListModel);
    } else if(index == 1) {
         ui->table->setModel(DoctorListModel);
    } else if(index == 2) {
        ui->table->setModel(PatientListModel);
    } else if(index == 3) {
         ui->table->setModel(PrescriotionListModel);
    } else if(index == 4) {
        ui->table->setModel(TreatmentListModel);
    } else if(index == 5) {
        ui->table->setModel(ComplantListModel);
    }
}

void MainWindow::addSale(QStringList & list) {
    salesListModel->addItem(list);
}

void MainWindow::addDoctor(QStringList & list) {
    DoctorListModel->addItem(list);
}

void MainWindow::addPatient(QStringList & list) {
    PatientListModel->addItem(list);
}

void MainWindow::addPrescriotion(QStringList & list) {
    PrescriotionListModel->addItem(list);
}

void MainWindow::addTreatment(QStringList & list) {
    TreatmentListModel->addItem(list);
}

void MainWindow::addComplant(QStringList & list) {
    ComplantListModel->addItem(list);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() == 0) {
        FormSales * form = new FormSales();
        connect(form, &FormSales::dataEntered, this, &MainWindow::addSale);
        form->show();
    } else     if(ui->comboBox->currentIndex() == 1) {
        FormDoctor * form = new FormDoctor();
        connect(form, &FoDoctor::dataEntered, this, &MainWindow::addDoctor);
        form->show();
    } else     if(ui->comboBox->currentIndex() == 2) {
        FormPatient * form = new FormPatient();
        connect(form, &ForPatient::dataEntered, this, &MainWindow::addPatient);
        form->show();
    } else     if(ui->comboBox->currentIndex() == 3) {
        FormPrescriotion * form = new FormPrescriotion();
        connect(form, &FormSalePrescriotion::dataEntered, this, &MainWindow::addPrescriotion);
        form->show();
    } else     if(ui->comboBox->currentIndex() == 4) {
        FormTreatment * form = new FormTreatment();
        connect(form, &FormSTreatment::dataEntered, this, &MainWindow::addTreatment);
        form->show();
    } else     if(ui->comboBox->currentIndex() == 5) {
        FormComplant * form = new FormComplant();
        connect(form, &FormComplant::dataEntered, this, &MainWindow::addComplant);
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
        //serup == true -> поиск идет
        // ui->pushButton_search->setEnabled(!setup);
        // ui->pushButton_delete->setEnabled(!setup);
        // ui->pushButton->setEnabled(!setup);
        // ui->pushButton_ok->setEnabled(setup);
        // ui->pushButton_ok->setVisible(setup);
        // ui->lineEdit_search->setVisible(setup);
        // ui->lineEdit_search->setEnabled(setup);
        // ui->radioButton->setVisible(setup);
        // ui->radioButton_2->setVisible(setup);
        // ui->radioButton->setEnabled(setup);
        // ui->radioButton_2->setEnabled(setup);
        // ui->comboBox->setEnabled(!setup);
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
    if (!indexes.isEmpty()) {
        QModelIndex index = indexes.first();
        if(ui->comboBox->currentIndex() == 2) {
            salesListModel->removeItem(index);
        }
    }
}


