/********************************************************************************
** Form generated from reading UI file 'formprescription.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPRESCRIPTION_H
#define UI_FORMPRESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FormPrescription
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormPrescription)
    {
        if (FormPrescription->objectName().isEmpty())
            FormPrescription->setObjectName("FormPrescription");
        FormPrescription->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormPrescription);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(FormPrescription);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FormPrescription, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FormPrescription, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FormPrescription);
    } // setupUi

    void retranslateUi(QDialog *FormPrescription)
    {
        FormPrescription->setWindowTitle(QCoreApplication::translate("FormPrescription", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPrescription: public Ui_FormPrescription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPRESCRIPTION_H
