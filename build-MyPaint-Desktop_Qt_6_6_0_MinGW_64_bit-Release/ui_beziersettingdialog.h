/********************************************************************************
** Form generated from reading UI file 'beziersettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERSETTINGDIALOG_H
#define UI_BEZIERSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BezierSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBoxM;
    QSpinBox *spinBoxN;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *BezierSettingDialog)
    {
        if (BezierSettingDialog->objectName().isEmpty())
            BezierSettingDialog->setObjectName("BezierSettingDialog");
        BezierSettingDialog->resize(250, 176);
        buttonBox = new QDialogButtonBox(BezierSettingDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 130, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBoxM = new QSpinBox(BezierSettingDialog);
        spinBoxM->setObjectName("spinBoxM");
        spinBoxM->setGeometry(QRect(120, 90, 42, 24));
        spinBoxM->setMinimum(10);
        spinBoxM->setMaximum(500);
        spinBoxN = new QSpinBox(BezierSettingDialog);
        spinBoxN->setObjectName("spinBoxN");
        spinBoxN->setGeometry(QRect(120, 50, 42, 24));
        spinBoxN->setMinimum(1);
        label = new QLabel(BezierSettingDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 41, 21));
        label_2 = new QLabel(BezierSettingDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 51, 21));

        retranslateUi(BezierSettingDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BezierSettingDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BezierSettingDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(BezierSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *BezierSettingDialog)
    {
        BezierSettingDialog->setWindowTitle(QCoreApplication::translate("BezierSettingDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BezierSettingDialog", "\346\254\241\346\225\260 n\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("BezierSettingDialog", "\351\207\207\346\240\267\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BezierSettingDialog: public Ui_BezierSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERSETTINGDIALOG_H
