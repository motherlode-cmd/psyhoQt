#ifndef FORMTREATMENT_H
#define FORMTREATMENT_H

#include <QDialog>

namespace Ui {
class formtreatment;
}

class formtreatment : public QDialog
{
    Q_OBJECT

public:
    explicit formtreatment(QWidget *parent = nullptr);
    ~formtreatment();

private:
    Ui::formtreatment *ui;
};

#endif // FORMTREATMENT_H
