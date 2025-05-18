#ifndef FORMFLIGHT_H
#define FORMFLIGHT_H

#include <QWidget>

namespace Ui {
class FormFlight;
}

class FormFlight : public QWidget
{
    Q_OBJECT

public:
    explicit FormFlight(QWidget *parent = nullptr);
    ~FormFlight();
signals:
    void dataEntered(QStringList & userData);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::FormFlight *ui;
};

#endif // FORMFLIGHT_H
