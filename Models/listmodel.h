#ifndef LISTMODEL_H
#define LISTMODEL_H
#include "QTableModel.h"
#include "../List/List.hpp"

class ListModel : public QTableModel {
    Q_OBJECT
public:
    ListModel(QObject *parent = nullptr);
    // Переопределение виртуальных методов базового класса
    void addItem(QStringList & newValue) override;
    void removeItem(QModelIndex & index) override;
    void search(const QString & searchString) override;
    QList<QStringList> * getQList() override;
    QStringList get_headers() const override;
private:
    List list;
};
#endif // LISTMODEL_H
