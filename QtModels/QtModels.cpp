#include "Models/Models.hpp"
#include <iostream>
#include "QtModels/QtModels.hpp"

QtModel::QtModel(QObject *parent) {}

// Переопределение виртуальных методов базового класса
void QtModel::addItem(QStringList & newValue) {
    db->insertRow(newValue);
    auto list = db->selectRows();
    populate(&list);
}

void QtModel::removeItem(QModelIndex & index) {
    db->deleteRow(values.at(index.row()).at(0));
    qDebug("Delete row id ",values.at(index.row()).at(0).toInt());
    auto list = db->selectRows();
    populate(&list);
}

void QtModel::search(const QString &searchString) {
    db->searchRows(searchString, "");
    auto list = db->selectRows();
    populate(&list);
}

QList<QStringList> *QtModel::getQList() {
    auto list = db->selectRows();
    values = list;
    return &list;
}

QStringList QtModel::get_headers() const
{
    QStringList headers;
    auto labels = tableLabels.at(type);
    for (auto label : labels) {
        headers << QString::fromStdString(label);
    }
    
    return headers;
}
