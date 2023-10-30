#ifndef CLIPWINDOWSETTINGDIALOG_H
#define CLIPWINDOWSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class ClipWindowSettingDialog;
}

class ClipWindowSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClipWindowSettingDialog(QWidget *parent = nullptr);
    ~ClipWindowSettingDialog();

    int XLeft_;
    int XRight_;
    int YTop_;
    int YBottom_;
    bool showClipWindow_;

private slots:
    void on_spinBoxXLeft_valueChanged(int arg1);

    void on_spinBoxXRight_valueChanged(int arg1);

    void on_spinBoxYTop_valueChanged(int arg1);

    void on_spinBoxYBottom_valueChanged(int arg1);

    void on_checkBox_clicked();

private:
    Ui::ClipWindowSettingDialog *ui;
};

#endif // CLIPWINDOWSETTINGDIALOG_H
