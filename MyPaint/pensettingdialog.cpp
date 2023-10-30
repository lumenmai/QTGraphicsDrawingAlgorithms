#include "pensettingdialog.h"
#include "ui_pensettingdialog.h"
#include <QColorDialog>

PenSettingDialog::PenSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PenSettingDialog)
{
    ui->setupUi(this);
}

PenSettingDialog::~PenSettingDialog()
{
    delete ui;
}

void PenSettingDialog::on_spinBox_valueChanged(int arg1)
{
    size_= arg1;
}


void PenSettingDialog::on_pushButton_clicked()
{
    color_ = QColorDialog::getColor(Qt::red, this,tr("颜色对话框 "),QColorDialog::ShowAlphaChannel);
}

