#include "beziersettingdialog.h"
#include "ui_beziersettingdialog.h"

BezierSettingDialog::BezierSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BezierSettingDialog)
{
    ui->setupUi(this);
    n_ = 3;
    m_ = 10;
    ui->spinBoxN->setValue(n_);
    ui->spinBoxM->setValue(m_);
}

BezierSettingDialog::~BezierSettingDialog()
{
    delete ui;
}

void BezierSettingDialog::on_spinBoxN_valueChanged(int arg1)
{
    n_ = arg1;
}


void BezierSettingDialog::on_spinBoxM_valueChanged(int arg1)
{
    m_ = arg1;
}

