#include "Models/Models.hpp"
#include <iostream>
#include "QtModels/QtModels.hpp"

QtModel::QtModel(QObject *parent) {}

// Переопределение виртуальных методов базового класса
void QtModel::addItem(QStringList & newValue) {
    auto labels = tableLabels.at(type);
    std::vector <std::pair<std::string, std::string>> values;
    for (int i = 0; i < newValue.size(); i++) {
        values.push_back({labels[i], newValue[i].toStdString()});
    }
    list.push_back(createElem(values, type));
}

void QtModel::removeItem(QModelIndex & index) {
    delete list[index.row()];
    list.erase(list.begin() + index.row());
}

void QtModel::search(const QString &searchString) {

}

QList<QStringList> *QtModel::getQList() {
    QList<QStringList> * data = new QList<QStringList>;
    for(auto row : list) {
        QStringList new_list;
        for (auto pair : row->get_row()) {
             new_list.append(QString::fromStdString(pair.second));
        }
        data->append(new_list);
    }
    return data;
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
