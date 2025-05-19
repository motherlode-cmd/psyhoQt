/********************************************************************************
** Form generated from reading UI file 'formtreatment.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTREATMENT_H
#define UI_FORMTREATMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FormTreatment
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormTreatment)
    {
        if (FormTreatment->objectName().isEmpty())
            FormTreatment->setObjectName("FormTreatment");
        FormTreatment->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormTreatment);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(FormTreatment);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FormTreatment, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FormTreatment, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FormTreatment);
    } // setupUi

    void retranslateUi(QDialog *FormTreatment)
    {
        FormTreatment->setWindowTitle(QCoreApplication::translate("FormTreatment", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTreatment: public Ui_FormTreatment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTREATMENT_H
