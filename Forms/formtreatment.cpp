#include "formtreatment.h"

FormTreatment::FormTreatment(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant FormTreatment::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex FormTreatment::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex FormTreatment::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int FormTreatment::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int FormTreatment::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant FormTreatment::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
