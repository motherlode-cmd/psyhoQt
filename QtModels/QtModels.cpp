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
    return {};
}

QStringList QtModel::get_headers() const
{
    QStringList headers;
    headers << "Номер паспорта" << "Номер билета" << "Номер рейса";
    return headers;
}
