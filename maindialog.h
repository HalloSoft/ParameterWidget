#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

    void accept();

private:
    Ui::MainDialog *ui;

    bool _databaseConnected = false;
};

#endif // MAINDIALOG_H
