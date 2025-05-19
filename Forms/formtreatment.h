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

private:
    Ui::FormTreatment *ui;
};

#endif // FORMTREATMENT_H
