#ifndef FORMPASSANGER_H
#define FORMPASSANGER_H

#include <QWidget>

namespace Ui {
class FormPassanger;
}

class FormPassanger : public QWidget
{
    Q_OBJECT

public:
    explicit FormPassanger(QWidget *parent = nullptr);
    ~FormPassanger();
signals:
    void dataEntered(QStringList & userData);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::FormPassanger *ui;
};

#endif // FORMPASSANGER_H
