#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Models/hashtablemodel.h"
#include "Models/listmodel.h"
#include "Models/avltreemodel.h"
#include "Models/QTableModel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void addPassanger(QStringList & list);
    void addSale(QStringList & list);
    void addFlight(QStringList & list);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_ok_clicked();

    void on_lineEdit_search_textEdited(const QString &arg1);

    void on_pushButton_delete_clicked();

private:
    void search_setup(bool setup);
    Ui::MainWindow *ui;

    QTableModel *  salesListModel = new ListModel();
    QTableModel *  flightAVLTreeModel = new AVLTreeModel();
    QTableModel *  passangerHashTableModel= new HashTableModel();

};
#endif // MAINWINDOW_H
