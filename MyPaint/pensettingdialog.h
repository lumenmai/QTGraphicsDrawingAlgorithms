#ifndef PENSETTINGDIALOG_H
#define PENSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class PenSettingDialog;
}

class PenSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PenSettingDialog(QWidget *parent = nullptr);
    ~PenSettingDialog();

    int size_;
    QColor color_;
private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::PenSettingDialog *ui;
};

#endif // PENSETTINGDIALOG_H
