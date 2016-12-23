#include "maindialog.h"
#include "ui_maindialog.h"

#include "qsqlconnectiondialog.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::accept()
{
    QSqlConnectionDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(dialog.driverName());
        db.setHostName(dialog.hostName());
        db.setDatabaseName(dialog.databaseName());
        db.setUserName(dialog.userName());
        db.setPassword("loot");
        _databaseConnected = db.open();

        qDebug() << "open:" << _databaseConnected;

        ui->widget->update();

        if(!_databaseConnected)
            qDebug() << db.lastError().text();
    }
}
