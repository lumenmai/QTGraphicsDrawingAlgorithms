/********************************************************************************
** Form generated from reading UI file 'clipwindowsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPWINDOWSETTINGDIALOG_H
#define UI_CLIPWINDOWSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ClipWindowSettingDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBoxYTop;
    QSpinBox *spinBoxXRight;
    QSpinBox *spinBoxYBottom;
    QSpinBox *spinBoxXLeft;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ClipWindowSettingDialog)
    {
        if (ClipWindowSettingDialog->objectName().isEmpty())
            ClipWindowSettingDialog->setObjectName("ClipWindowSettingDialog");
        ClipWindowSettingDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ClipWindowSettingDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBoxYTop = new QSpinBox(ClipWindowSettingDialog);
        spinBoxYTop->setObjectName("spinBoxYTop");
        spinBoxYTop->setGeometry(QRect(180, 50, 42, 24));
        spinBoxYTop->setMaximum(999999);
        spinBoxXRight = new QSpinBox(ClipWindowSettingDialog);
        spinBoxXRight->setObjectName("spinBoxXRight");
        spinBoxXRight->setGeometry(QRect(280, 120, 42, 24));
        spinBoxXRight->setMaximum(999999);
        spinBoxYBottom = new QSpinBox(ClipWindowSettingDialog);
        spinBoxYBottom->setObjectName("spinBoxYBottom");
        spinBoxYBottom->setGeometry(QRect(180, 190, 42, 24));
        spinBoxYBottom->setMaximum(999999);
        spinBoxXLeft = new QSpinBox(ClipWindowSettingDialog);
        spinBoxXLeft->setObjectName("spinBoxXLeft");
        spinBoxXLeft->setGeometry(QRect(80, 120, 42, 24));
        spinBoxXLeft->setMaximum(999999);
        checkBox = new QCheckBox(ClipWindowSettingDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(50, 230, 91, 22));
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        label = new QLabel(ClipWindowSettingDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 120, 41, 21));
        label_2 = new QLabel(ClipWindowSettingDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 120, 51, 21));
        label_3 = new QLabel(ClipWindowSettingDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 50, 41, 21));
        label_4 = new QLabel(ClipWindowSettingDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 190, 61, 21));

        retranslateUi(ClipWindowSettingDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ClipWindowSettingDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ClipWindowSettingDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ClipWindowSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *ClipWindowSettingDialog)
    {
        ClipWindowSettingDialog->setWindowTitle(QCoreApplication::translate("ClipWindowSettingDialog", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("ClipWindowSettingDialog", "\346\230\276\347\244\272\350\243\201\345\211\252\347\252\227\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("ClipWindowSettingDialog", "XLeft:", nullptr));
        label_2->setText(QCoreApplication::translate("ClipWindowSettingDialog", "XRight:", nullptr));
        label_3->setText(QCoreApplication::translate("ClipWindowSettingDialog", "YTop:", nullptr));
        label_4->setText(QCoreApplication::translate("ClipWindowSettingDialog", "YBottom:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClipWindowSettingDialog: public Ui_ClipWindowSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPWINDOWSETTINGDIALOG_H
