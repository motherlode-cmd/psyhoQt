#ifndef FORMSALES_H
#define FORMSALES_H

#include <QWidget>

namespace Ui {
class FormSales;
}

class FormSales : public QWidget
{
    Q_OBJECT

public:
    explicit FormSales(QWidget *parent = nullptr);
    ~FormSales();
signals:
    void dataEntered(QStringList &userData);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::FormSales *ui;
};

#endif // FORMSALES_H
