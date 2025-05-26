#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Models/Models.hpp"
#include "QtModels/QtModels.hpp"
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
    void addDoctor(QStringList & list);
    void addPatient(QStringList & list);
    void addPrescriotion(QStringList & list);
    void addTreatment(QStringList & list);
    void addComplant(QStringList & list);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_delete_clicked();

    void log_in_postgres();

private:
    void search_setup(bool setup);
    Ui::MainWindow *ui;
    QSqlDatabase db;

    QTableModel *  DoctorListModel ;//= new QtModel(ui,ElementType::Doctor, std::vector <Doctor*>{});
    QTableModel *  PatientListModel ;//= new QtModel(ui,ElementType::Patient, std::vector <Patient*>{});
    QTableModel *  PrescriotionListModel ;//= new QtModel(ui,ElementType::Prescriotion, std::vector <Prescriotion*>{});
    QTableModel *  TreatmentListModel ;//= new QtModel(ui,ElementType::Treatment, std::vector <Treatment*>{});
    QTableModel *  ComplantListModel ;//= new QtModel(ui,ElementType::Complant, std::vector <Complant*>{});
};
#endif // MAINWINDOW_H
