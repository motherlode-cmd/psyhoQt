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
    ui->comboBox->addItem("Пассажиры");
    ui->comboBox->addItem("Авиарейсы");
    ui->comboBox->addItem("Билеты");
    search_setup(false);
    this->ui->table->setModel(passangerHashTableModel);
    ui->table->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0) {
         ui->table->setModel(salesListModel);
        ui->pushButton_search->setVisible(true);
    } else if(index == 1) {
         ui->table->setModel(salesListModel);
        ui->pushButton_search->setVisible(true);
    } else if(index == 2) {
        ui->table->setModel(salesListModel);
        ui->pushButton_search->setVisible(false);
    } 
}

void MainWindow::addPassanger(QStringList & list) {
    passangerHashTableModel->addItem(list);
}
void MainWindow::addSale(QStringList & list) {
    salesListModel->addItem(list);
}
void MainWindow::addFlight(QStringList & list) {
    flightAVLTreeModel->addItem(list);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() == 2) {
        FormSales * form = new FormSales();
        connect(form, &FormSales::dataEntered, this, &MainWindow::addSale);
        form->show();
    }
}


void MainWindow::on_pushButton_search_clicked()
{
    search_setup(true);
    if(ui->comboBox->currentIndex() == 0) {
        ui->radioButton->setText("Поиск пассажира по ФИО");
        ui->radioButton_2->setText("Поиск пассажира по пасспорту");
    } else if(ui->comboBox->currentIndex() == 1) {
        ui->radioButton->setText("Поиск авиарейса по номеру");
        ui->radioButton_2->setText("Поиск авиарейса по названию аэропорта");
    }
}

void MainWindow::search_setup(bool setup)
{
    //serup == true -> поиск идет
    ui->pushButton_search->setEnabled(!setup);
    ui->pushButton_delete->setEnabled(!setup);
    ui->pushButton->setEnabled(!setup);
    ui->pushButton_ok->setEnabled(setup);
    ui->pushButton_ok->setVisible(setup);
    ui->lineEdit_search->setVisible(setup);
    ui->lineEdit_search->setEnabled(setup);
    ui->radioButton->setVisible(setup);
    ui->radioButton_2->setVisible(setup);
    ui->radioButton->setEnabled(setup);
    ui->radioButton_2->setEnabled(setup);
    ui->comboBox->setEnabled(!setup);
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


