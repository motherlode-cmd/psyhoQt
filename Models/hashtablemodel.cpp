#include "hashtablemodel.h"
HashTableModel::HashTableModel(QObject *parent) {

}
// Переопределение виртуальных методов базового класса
void HashTableModel::addItem(QStringList & newValue) {
    Passenger passanger(newValue);
    table.insert(passanger);
    populate(getQList());
    //std::cout<<"size "<<values->size()<<std::endl;
}

void HashTableModel::removeItem(QModelIndex & index) {
    QStringList info = values.at(index.row());
    Passenger remove_passenger(info);
    table.delete_value(remove_passenger);
    populate(getQList());
}

void HashTableModel::search(const QString &searchString) {
    populate(table.get_search_data(searchString));
}

QList<QStringList> *HashTableModel::getQList() {
    return table.get_data();
}

void HashTableModel::alt_search(const QString &searchString)
{
    populate(table.get_search_name(searchString));
}

QStringList HashTableModel::get_headers() const
{
    QStringList headers;
    headers << "Номер паспорта" << "Место и дата выдачи" << "Фамилия Имя Отчество" << "Дата рождения";
    return headers;
}
