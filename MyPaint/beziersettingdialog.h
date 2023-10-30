#ifndef BEZIERSETTINGDIALOG_H
#define BEZIERSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class BezierSettingDialog;
}

class BezierSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BezierSettingDialog(QWidget *parent = nullptr);
    ~BezierSettingDialog();
    int n_;
    int m_;

private slots:
    void on_spinBoxN_valueChanged(int arg1);

    void on_spinBoxM_valueChanged(int arg1);

private:
    Ui::BezierSettingDialog *ui;
};

#endif // BEZIERSETTINGDIALOG_H
