#ifndef FORMDOCTOR_H
#define FORMDOCTOR_H

#include <QDialog>

namespace Ui {
class FormDoctor;
}

class FormDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit FormDoctor(QWidget *parent = nullptr);
    ~FormDoctor();

private:
    Ui::FormDoctor *ui;
};

#endif // FORMDOCTOR_H
