#include "Models/Models.hpp"
#include <iostream>
#include "QtModels/QtModels.hpp"

QtModel::QtModel(QObject *parent) {}

// Переопределение виртуальных методов базового класса
void QtModel::addItem(QStringList & newValue) {
    db->insertRow(newValue);
}

void QtModel::removeItem(QModelIndex & index) {
    db->deleteRow(values.at(index.row()).at(0));
}

void QtModel::search(const QString &searchString) {
    db->searchRows(searchString, "");
}

QList<QStringList> *QtModel::getQList() {
    auto list = db->selectRows();
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
