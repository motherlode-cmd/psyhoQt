#ifndef FORMTREATMENT_H
#define FORMTREATMENT_H

#include <QDialog>

namespace Ui {
class FormTreatment;
}

class FormTreatment : public QDialog
{
    Q_OBJECT

public:
    explicit FormTreatment(QWidget *parent = nullptr);
    ~FormTreatment();
    headerData(int section, Qt::Orientation orientation, int role) const;
    index(int row, int column, const QModelIndex &parent) const;
    parent(const QModelIndex &index) const;
    rowCount(const QModelIndex &parent) const;
    columnCount(const QModelIndex &parent) const;
    data(const QModelIndex &index, int role) const;

private:
    Ui::FormTreatment *ui;
};

#endif // FORMTREATMENT_H
