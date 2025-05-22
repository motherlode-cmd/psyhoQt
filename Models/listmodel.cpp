#include "Models/listmodel.h"
#include <iostream>

ListModel::ListModel(QObject *parent) {
}
// Переопределение виртуальных методов базового класса
void ListModel::addItem(QStringList & newValue) {
    Sales sale(newValue);
    list.insert(sale);
    populate(getQList());
    std::cout<<values.size()<<std::endl;
}
void ListModel::removeItem(QModelIndex & index) {
    std::string key_delete = values.at(index.row()).at(1).toStdString();
    list.delete_value(key_delete);
    populate(getQList());
}
void ListModel::search(const QString &searchString) {
    //return new QList<QStringList>();
}

QList<QStringList> *ListModel::getQList() {
    return list.get_data();
}

QStringList ListModel::get_headers() const
{
    QStringList headers;
    headers << "Номер паспорта" << "Номер билета" << "Номер рейса";
    return headers;
}
