#include "avltreemodel.h"
AVLTreeModel::AVLTreeModel(QObject *parent) {

}
// Переопределение виртуальных методов базового класса
void AVLTreeModel::addItem(QStringList & newValue) {
    Flight flight(newValue);
    tree.insert(flight);
    populate(getQList());
}
void AVLTreeModel::removeItem(QModelIndex & index) {
    QStringList info = values.at(index.row());
    Flight flight(info);
    tree.deleteValue(flight);
    populate(getQList());
}

void AVLTreeModel::search(const QString &searchString) {
    populate(tree.get_search_data(searchString));
}

QList<QStringList> * AVLTreeModel::getQList() {
    return tree.get_data();
}

void AVLTreeModel::alt_search(const QString &searchString)
{
    populate(tree.get_search_airport(searchString));
}

QStringList AVLTreeModel::get_headers() const
{
    QStringList headers;
    headers << "Номер рейса" << "Аэропорт прибытия" << "Аэропорт отправки";
    headers << "Авиакомпания" << "Дата отправления" << "Время отправления";
    headers << "Номер места" << "Свободных мест";
    return headers;
}
