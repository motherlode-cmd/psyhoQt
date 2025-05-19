#ifndef FORMPATIENT_H
#define FORMPATIENT_H

#include <QDialog>

namespace Ui {
class FormPatient;
}

class FormPatient : public QDialog
{
    Q_OBJECT

public:
    explicit FormPatient(QWidget *parent = nullptr);
    ~FormPatient();

private:
    Ui::FormPatient *ui;
};

#endif // FORMPATIENT_H
