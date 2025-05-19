#ifndef FORMPRESCRIPTION_H
#define FORMPRESCRIPTION_H

#include <QDialog>

namespace Ui {
class formprescription;
}

class formprescription : public QDialog
{
    Q_OBJECT

public:
    explicit formprescription(QWidget *parent = nullptr);
    ~formprescription();

private:
    Ui::formprescription *ui;
};

#endif // FORMPRESCRIPTION_H
