#include "QtModels.hpp"
#include <iostream>

QtModel::QtModel(QObject *parent) {}

// Переопределение виртуальных методов базового класса
void QtModel::addItem(QStringList & newValue) {
    
}

void QtModel::removeItem(QModelIndex & index) {

}

void QtModel::search(const QString &searchString) {

}

QList<QStringList> *QtModel::getQList() {
    QList<QStringList> * data = new QList<QStringList>;
    for(auto row : list) {
        QStringList new_list;
        for (auto pair : row.get_row()) {
             new_list.append(QString::fromStdString(pair.second));
        }
        data->append(new_list);
    }
    return data;
}

QStringList QtModel::get_headers() const
{
    QStringList headers;

    for auto (label : labels) {
        headers << label;
    }
    
    return headers;
}
