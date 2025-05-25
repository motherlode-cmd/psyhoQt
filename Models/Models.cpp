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
    }
    QSqlQuery query;

    auto colunmNames = this->getColumnNames();
    auto colunmTypes = this->getColumnTypes();
    auto tableNmae = this->getTableName();

    QString isertedColumns = "";
    QString insertedValuesString = "";
    for (int i = 0; i < colunmNames.size(); i++)
    {
        if (colunmNames[i] != "id")
        {
            isertedColumns += colunmNames[i];
            if (colunmTypes.at(i) == "string")
            {
                insertedValuesString += QString("':%1'").arg(colunmNames[i]);
            }
            else
            {
                insertedValuesString += ":" + colunmNames[i];
            }
        }
        if (i < colunmNames.size() - 1)
        {
            isertedColumns += ", ";
        }
    }

    query.prepare(QString("INSERT INTO employee (%1) "
                          "VALUES (%2)")
                      .arg(isertedColumns)
                      .arg(insertedValuesString));

    for (int i = 1; i < row.size(); i++) {
        query.bindValue(QString(":%1").arg(colunmNames[i]), row.at(i));
    }

    query.exec();
}

void Database::deleteRow(const QString id)
{
}
void Database::searchRows(const QString &searchString)
{
}
void Database::selectRows()
{
}

std::time_t string_to_time_t(const std::string &time_str, const std::string &format = "%Y-%m-%d %H:%M:%S")
{
    QSqlQuery query;

    std::tm tm = {};
    std::istringstream ss(time_str);
    ss >> std::get_time(&tm, format.c_str());
    if (ss.fail())
    {
        throw std::runtime_error("Failed to parse time string");
    }
    return std::mktime(&tm);
}

std::string time_t_to_string(std::time_t time, const std::string &format = "%Y-%m-%d %H:%M:%S")
{
    std::tm tm = *std::localtime(&time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), format.c_str(), &tm);
    return std::string(buffer);
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

QString Doctor::getTableName()
{
    return "table";
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
    labels_values.append("id");
    labels_values.append("full_name");
    labels_values.append("speciality");
    labels_values.append("phone");
    labels_values.append("email");
    return labels_values;
}

QString Patient::getTableName()
{
    return "table";
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
    labels_values.append("id");
    labels_values.append("full_name");
    labels_values.append("birth_date");
    labels_values.append("inpatient");
    return labels_values;
}

QString Prescriotion::getTableName()
{
    return "table";
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
    labels_values.append("id");
    labels_values.append("doctor_id");
    labels_values.append("medicine");
    labels_values.append("issue_date");
    labels_values.append("issue_time");
    labels_values.append("dossage_mg");
    labels_values.append("inclassions");
    return labels_values;
}

QString Treatment::getTableName()
{
    return "table";
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
    labels_values.append("id");
    labels_values.append("patient_id");
    labels_values.append("start_date");
    labels_values.append("diagnosis");
    labels_values.append("prescription_id");
    labels_values.append("end_date");
    labels_values.append("note");
    return labels_values;
}

QString Complant::getTableName()
{
    return "table";
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
    labels_values.append("id");
    labels_values.append("doctor_id");
    labels_values.append("patient_id");
    labels_values.append("status");
    labels_values.append("coplaint_date");
    labels_values.append("coplaint_message");
    return labels_values;
}