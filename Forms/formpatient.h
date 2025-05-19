#ifndef FORMPATIENT_H
#define FORMPATIENT_H

#include <QDialog>

namespace Ui {
class formpatient;
}

class formpatient : public QDialog
{
    Q_OBJECT

public:
    explicit formpatient(QWidget *parent = nullptr);
    ~formpatient();

private:
    Ui::formpatient *ui;
};

#endif // FORMPATIENT_H
