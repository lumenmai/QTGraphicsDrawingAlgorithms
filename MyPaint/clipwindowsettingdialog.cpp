#include "clipwindowsettingdialog.h"
#include "ui_clipwindowsettingdialog.h"

ClipWindowSettingDialog::ClipWindowSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClipWindowSettingDialog)
{
    ui->setupUi(this);
    XLeft_ = 200;
    XRight_ = 600;
    YTop_ = 400;
    YBottom_ = 100;
    showClipWindow_ = true;
    ui->spinBoxXLeft->setValue(XLeft_);
    ui->spinBoxXRight->setValue(XRight_);
    ui->spinBoxYTop->setValue(YTop_);
    ui->spinBoxYBottom->setValue(YBottom_);
    ui->checkBox->setCheckState(Qt::CheckState::Checked);
}

ClipWindowSettingDialog::~ClipWindowSettingDialog()
{
    delete ui;
}

void ClipWindowSettingDialog::on_spinBoxXLeft_valueChanged(int arg1)
{
    XLeft_ = arg1;
}


void ClipWindowSettingDialog::on_spinBoxXRight_valueChanged(int arg1)
{
    XRight_ = arg1;
}


void ClipWindowSettingDialog::on_spinBoxYTop_valueChanged(int arg1)
{
    YTop_ = arg1;
}


void ClipWindowSettingDialog::on_spinBoxYBottom_valueChanged(int arg1)
{
    YBottom_ = arg1;
}

void ClipWindowSettingDialog::on_checkBox_clicked()
{
    showClipWindow_ = !showClipWindow_;
}

