/********************************************************************************
** Form generated from reading UI file 'pensettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENSETTINGDIALOG_H
#define UI_PENSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PenSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *PenSettingDialog)
    {
        if (PenSettingDialog->objectName().isEmpty())
            PenSettingDialog->setObjectName("PenSettingDialog");
        PenSettingDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(PenSettingDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(PenSettingDialog);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(140, 130, 42, 22));
        spinBox->setMinimum(1);
        spinBox->setValue(1);
        label = new QLabel(PenSettingDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 120, 53, 41));
        label_2 = new QLabel(PenSettingDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 160, 53, 41));
        pushButton = new QPushButton(PenSettingDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 170, 31, 24));

        retranslateUi(PenSettingDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PenSettingDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PenSettingDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PenSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *PenSettingDialog)
    {
        PenSettingDialog->setWindowTitle(QCoreApplication::translate("PenSettingDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PenSettingDialog", "\347\224\273\347\254\224\345\244\247\345\260\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("PenSettingDialog", "\347\224\273\347\254\224\351\242\234\350\211\262\357\274\232", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PenSettingDialog: public Ui_PenSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENSETTINGDIALOG_H
