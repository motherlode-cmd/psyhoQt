#ifndef LISTMODEL_H
#define LISTMODEL_H
#include "QTableModel.h"
#include "../Models/Models.hpp"

class QtModel : public QTableModel {
    Q_OBJECT
public:
    QtModel(QObject *parent = nullptr);
    // Переопределение виртуальных методов базового класса
    void addItem(QStringList & newValue) override;
    void removeItem(QModelIndex & index) override;
    void search(const QString & searchString) override;
    QList<QStringList> * getQList() override;
    QStringList get_headers() const override;
private:
    std::vector <TableElement> list;
    std::vector <std::string> labels;
};
#endif // LISTMODEL_H
