#ifndef FORMCOMPLANT_H
#define FORMCOMPLANT_H

#include <QDialog>

namespace Ui {
class formcomplant;
}

class formcomplant : public QDialog
{
    Q_OBJECT

public:
    explicit formcomplant(QWidget *parent = nullptr);
    ~formcomplant();

private:
    Ui::formcomplant *ui;
};

#endif // FORMCOMPLANT_H
