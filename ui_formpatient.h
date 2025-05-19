/********************************************************************************
** Form generated from reading UI file 'formpatient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPATIENT_H
#define UI_FORMPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FormPatient
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormPatient)
    {
        if (FormPatient->objectName().isEmpty())
            FormPatient->setObjectName("FormPatient");
        FormPatient->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormPatient);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(FormPatient);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FormPatient, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FormPatient, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FormPatient);
    } // setupUi

    void retranslateUi(QDialog *FormPatient)
    {
        FormPatient->setWindowTitle(QCoreApplication::translate("FormPatient", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPatient: public Ui_FormPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPATIENT_H
