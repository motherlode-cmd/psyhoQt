#ifndef FORMCOMPLANT_H
#define FORMCOMPLANT_H

#include <QDialog>

namespace Ui {
class FormComplant;
}

class FormComplant : public QDialog
{
    Q_OBJECT

public:
    explicit FormComplant(QWidget *parent = nullptr);
    ~FormComplant();

private:
    Ui::FormComplant *ui;
};

#endif // FORMCOMPLANT_H
