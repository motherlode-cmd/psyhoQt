#ifndef AVLTREEMODEL_H
#define AVLTREEMODEL_H
#include "QTableModel.h"
#include "../Tree/AVLTree.hpp"

class AVLTreeModel : public QTableModel {
    Q_OBJECT
public:
    AVLTreeModel(QObject *parent = nullptr);
    // Переопределение виртуальных методов базового класса
    void addItem(QStringList & newValue) override;
    void removeItem(QModelIndex & index) override;
    void search(const QString & searchString) override;
    QList<QStringList> * getQList() override;
    void alt_search(const QString & searchString) override;
    QStringList get_headers() const override;
private:
    AVLTree tree;
};
#endif // AVLTREEMODEL_H
