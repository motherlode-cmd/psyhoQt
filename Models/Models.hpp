#ifndef MODELS_H
#define MODELS_H
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>
#include <iomanip>
#include "constants/Tables.hpp"
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QString>

class Database
{
public:
    virtual ~Database() = default;
    void insertRow(QStringList & row);
    void deleteRow(const QString id);
    QList<QStringList> searchRows(const QString &searchString, const QString &columnSearch);
    QList<QStringList> selectRows();
    virtual QStringList getColumnNames() = 0;
    virtual QStringList getColumnTypes() = 0;
    virtual QString getTableName() = 0;
    virtual QList<QStringList> processSelectQuery(QSqlQuery& query) = 0;
protected:
};

Database *createElem(QSqlDatabase * connection, ElementType type);
class Doctor : public Database
{
public:
    Doctor() = default;
    ~Doctor() = default;
    QStringList getColumnNames();
    QString getTableName();
    QStringList getColumnTypes();
    QList<QStringList> processSelectQuery(QSqlQuery& query);
    // int id;
    // std::string full_name;
    // std::string speciality;
    // std::string phone;
    // std::string email;
};

class Patient : public Database
{
public:
    Patient() = default;
    ~Patient() = default;
    QStringList getColumnNames();
    QString getTableName();
    QStringList getColumnTypes();
    QList<QStringList> processSelectQuery(QSqlQuery& query);

    // int id;
    // std::string full_name;
    // std::time_t birth_date;
    // bool inpatient;
};

class Prescriotion : public Database
{
public:
    Prescriotion() = default;
    ~Prescriotion() = default;
    QStringList getColumnNames();
    QString getTableName();
    QStringList getColumnTypes();
    QList<QStringList> processSelectQuery(QSqlQuery& query);

    // int id;
    // int doctor_id;
    // std::string medicine;
    // std::time_t issue_date;
    // std::time_t issue_time;
    // double dossage_mg;
    // std::string inclassions;
};

class Treatment : public Database
{
public:
    Treatment() = default;
    ~Treatment() = default;
    QStringList getColumnNames();
    QString getTableName();
    QStringList getColumnTypes();
    QList<QStringList> processSelectQuery(QSqlQuery& query);

    // int id;
    // int patient_id;
    // std::time_t start_date;
    // std::string diagnosis;
    // int prescription_id;
    // std::time_t end_date;
    // std::string note;
};

class Complant : public Database
{
public:
    Complant() = default;
    ~Complant() = default;
    QStringList getColumnNames();
    QString getTableName();
    QStringList getColumnTypes();
    QList<QStringList> processSelectQuery(QSqlQuery& query);

    // int id;
    // int doctor_id;
    // int patient_id;
    // std::string status;
    // std::time_t coplaint_date;
    // std::string coplaint_message;
};

#endif // MODELS_H
