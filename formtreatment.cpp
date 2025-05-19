#include "formtreatment.h"

formtreatment::formtreatment(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant formtreatment::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex formtreatment::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex formtreatment::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int formtreatment::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int formtreatment::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant formtreatment::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
