#ifndef HASHTABLEMODEL_H
#define HASHTABLEMODEL_H
#include "QTableModel.h"
#include "qobject.h"
#include "../HashTable/HashTable.hpp"

class HashTableModel : public QTableModel {
    Q_OBJECT
public:
    HashTableModel(QObject *parent = nullptr);
    // Переопределение виртуальных методов базового класса
    void addItem(QStringList & newValue) override;
    void removeItem(QModelIndex & index) override;
    void search(const QString & searchString) override;
    QList<QStringList> * getQList() override;
    void alt_search(const QString & searchString) override;
    QStringList get_headers() const override;
private:
    Hash_table table;
};
#endif // HASHTABLEMODEL_H
