#include "QtModels.hpp"
#include <iostream>

QtModel::QtModel(QObject *parent) {}

// Переопределение виртуальных методов базового класса
void QtModel::addItem(QStringList & newValue) {
    Sales sale(newValue);
    list.insert(sale);
    populate(getQList());
    std::cout<<values.size()<<std::endl;
}

void QtModel::removeItem(QModelIndex & index) {
    std::string key_delete = values.at(index.row()).at(1).toStdString();
    list.delete_value(key_delete);
    populate(getQList());
}

void QtModel::search(const QString &searchString) {
    //return new QList<QStringList>();
}

QList<QStringList> *QtModel::getQList() {
    return list.get_data();
}

QStringList QtModel::get_headers() const
{
    QStringList headers;
    headers << "Номер паспорта" << "Номер билета" << "Номер рейса";
    return headers;
}
