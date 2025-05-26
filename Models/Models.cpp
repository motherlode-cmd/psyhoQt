#include "Models/Models.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>

void Database::insertRow(QStringList &row)
{
    auto db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        db.open();
        std::cout << "Noe opened" << std::endl;
    }
    QSqlQuery query;

    auto colunmNames = this->getColumnNames();
    auto colunmTypes = this->getColumnTypes();
    auto tableNmae = this->getTableName();

    QString isertedColumns = "";
    QString insertedValuesString = "";
    for (int i = 1; i < colunmNames.size(); i++)
    {

        isertedColumns += colunmNames[i];
        insertedValuesString += ":" + colunmNames[i]; 

        if (i < colunmNames.size() - 1)
        {
            isertedColumns += ", ";
            insertedValuesString += ", ";
        }
    }

    query.prepare(QString("INSERT INTO %1 (%2) "
                          "VALUES (%3)")
                      .arg(tableNmae)
                      .arg(isertedColumns)
                      .arg(insertedValuesString));

    for (int i = 0; i < row.size(); i++)
    {
        query.bindValue(QString(":%1").arg(colunmNames[i+1]), row.at(i));
    }

    bool isOk = query.exec();
    if (!isOk)
    {
        qDebug() << "SQL Error:" << query.lastError().text();
    }
}

void Database::deleteRow(const QString id)
{
    auto db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query;

    auto tableNmae = this->getTableName();
    auto colunmNames = this->getColumnNames();

    query.prepare(QString("DELETE FROM %1 "
                          "WHERE %2 = :id")
                      .arg(tableNmae)
                      .arg(colunmNames[0]));
    query.bindValue(":id", id);
    bool isOk = query.exec();
    if (!isOk)
    {
        qDebug() << "SQL Error:" << query.lastError().text();
    }
}

QList<QStringList> Database::searchRows(const QString &searchString, const QString &columnSearch)
{
    auto db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query;

    auto tableNmae = this->getTableName();
    query.prepare(QString("SELECT * FROM %1"
                          "WHERE %2 LIKE '%3'")
                      .arg(tableNmae)
                      .arg(columnSearch)
                      .arg(searchString));
    bool isOk = query.exec();
    if (!isOk)
    {
        qDebug() << "SQL Error:" << query.lastError().text();
    }

    return this->processSelectQuery(query);
}

QList<QStringList> Database::selectRows()
{
    auto db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query;

    auto tableNmae = this->getTableName();
    qDebug() << "SELECT in " << tableNmae;

    query.prepare(QString("SELECT * FROM %1")
                      .arg(tableNmae));
    bool isOk = query.exec();
    if (!isOk)
    {
        qDebug() << "SQL Error:" << query.lastError().text();
    }

    return this->processSelectQuery(query);
}

Database *createElem(QSqlDatabase *connection, ElementType type)
{
    switch (type)
    {
    case ElementType::Doctor:
        return new Doctor();
    case ElementType::Patient:
        return new Patient();
    case ElementType::Prescriotion:
        return new Prescriotion();
    case ElementType::Treatment:
        return new Treatment();
    case ElementType::Complant:
        return new Complant();
    case ElementType::Unknown:
        return nullptr;
    default:
        return nullptr;
    }
}

QList<QStringList> Doctor::processSelectQuery(QSqlQuery &query)
{
    QList<QStringList> result = {};
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString full_name = query.value(1).toString();
        QString speciality = query.value(2).toString();
        QString phone = query.value(3).toString();
        QString email = query.value(4).toString();

        result.append(QStringList{
            id,
            full_name,
            speciality,
            phone,
            email});
    }
    return result;
}

QString Doctor::getTableName()
{
    return "doctors";
}

QStringList Doctor::getColumnTypes()
{
    QStringList column_types;
    column_types.append("int");
    column_types.append("string");
    column_types.append("string");
    column_types.append("string");
    column_types.append("string");
    return column_types;
}

QStringList Doctor::getColumnNames()
{
    QStringList labels_values;
    labels_values.append("doctor_id");
    labels_values.append("full_name");
    labels_values.append("specialty");
    labels_values.append("phone");
    labels_values.append("email");
    return labels_values;
}

QList<QStringList> Patient::processSelectQuery(QSqlQuery &query)
{
    QList<QStringList> result = {};
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString full_name = query.value(1).toString();
        QString birth_date = query.value(2).toString();
        QString inpatient = query.value(3).toString();

        result.append(QStringList{
            id,
            full_name,
            birth_date,
            inpatient});
    }
    return result;
}

QString Patient::getTableName()
{
    return "patients";
}

QStringList Patient::getColumnTypes()
{
    QStringList column_types;
    column_types.append("int");
    column_types.append("string");
    column_types.append("date");
    column_types.append("string");
    return column_types;
}

QStringList Patient::getColumnNames()
{
    QStringList labels_values;
    labels_values.append("patient_id");
    labels_values.append("full_name");
    labels_values.append("birth_date");
    labels_values.append("inpatient");
    return labels_values;
}

QList<QStringList> Prescriotion::processSelectQuery(QSqlQuery &query)
{
    QList<QStringList> result = {};
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString doctor_id = query.value(1).toString();
        QString medicine = query.value(2).toString();
        QString issue_date = query.value(3).toString();
        QString issue_time = query.value(4).toString();
        QString dossage_mg = query.value(5).toString();
        QString inclassions = query.value(6).toString();

        result.append(QStringList{
            id,
            doctor_id,
            medicine,
            issue_date,
            issue_time,
            dossage_mg,
            inclassions});
    }
    return result;
}

QString Prescriotion::getTableName()
{
    return "prescriptions";
}

QStringList Prescriotion::getColumnTypes()
{
    QStringList column_types;
    column_types.append("int");
    column_types.append("int");
    column_types.append("string");
    column_types.append("date");
    column_types.append("date");
    column_types.append("double");
    column_types.append("string");
    return column_types;
}

QStringList Prescriotion::getColumnNames()
{
    QStringList labels_values;
    labels_values.append("prescription_id");
    labels_values.append("doctor_id");
    labels_values.append("medicine");
    labels_values.append("issue_date");
    labels_values.append("issue_time");
    labels_values.append("dossage_mg");
    labels_values.append("inclassions");
    return labels_values;
}

QList<QStringList> Treatment::processSelectQuery(QSqlQuery &query)
{
    QList<QStringList> result = {};
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString patient_id = query.value(1).toString();
        QString start_date = query.value(2).toString();
        QString diagnosis = query.value(3).toString();
        QString prescription_id = query.value(4).toString();
        QString end_date = query.value(5).toString();
        QString note = query.value(6).toString();

        result.append(QStringList{
            id,
            patient_id,
            start_date,
            diagnosis,
            prescription_id,
            end_date,
            note});
    }
    return result;
}

QString Treatment::getTableName()
{
    return "treatments";
}

QStringList Treatment::getColumnTypes()
{
    QStringList column_types;
    column_types.append("int");
    column_types.append("int");
    column_types.append("date");
    column_types.append("string");
    column_types.append("int");
    column_types.append("date");
    column_types.append("string");
    return column_types;
}

QStringList Treatment::getColumnNames()
{
    QStringList labels_values;
    labels_values.append("treatment_id");
    labels_values.append("patient_id");
    labels_values.append("start_date");
    labels_values.append("diagnosis");
    labels_values.append("prescription_id");
    labels_values.append("end_date");
    labels_values.append("note");
    return labels_values;
}

QList<QStringList> Complant::processSelectQuery(QSqlQuery &query)
{
    QList<QStringList> result = {};
    while (query.next())
    {

        qDebug() << "SQL NextRow:" << query.value(0);

        QString id = query.value(0).toString();
        QString doctor_id = query.value(1).toString();
        QString patient_id = query.value(2).toString();
        QString status = query.value(3).toString();
        QString coplaint_date = query.value(4).toString();
        QString coplaint_message = query.value(5).toString();

        result.append(QStringList{
            id,
            doctor_id,
            patient_id,
            status,
            coplaint_date,
            coplaint_message});
    }
    return result;
}

QString Complant::getTableName()
{
    return "complaints";
}

QStringList Complant::getColumnTypes()
{
    QStringList column_types;
    column_types.append("int");
    column_types.append("int");
    column_types.append("int");
    column_types.append("string");
    column_types.append("date");
    column_types.append("string");
    return column_types;
}

QStringList Complant::getColumnNames()
{
    QStringList labels_values;
    labels_values.append("complaint_id");
    labels_values.append("doctor_id");
    labels_values.append("patient_id");
    labels_values.append("status");
    labels_values.append("complaint_date");
    labels_values.append("complaint_message");
    return labels_values;
}