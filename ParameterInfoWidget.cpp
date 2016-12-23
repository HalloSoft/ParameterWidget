#include "ParameterInfoWidget.h"
#include "ui_ParameterInfoWidget.h"

#include <QSqlTableModel>

ParameterInfoWidget::ParameterInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterInfoWidget)
{
    ui->setupUi(this);


}

ParameterInfoWidget::~ParameterInfoWidget()
{
    delete ui;
}

void ParameterInfoWidget::update()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("qry_paramsimple");
    //model->setTable("param");
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("A"));
    //model->setHeaderData(1, Qt::Horizontal, tr("S"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(model);
    //ui->tableView->show();
}
