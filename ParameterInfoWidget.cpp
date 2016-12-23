#include "ParameterInfoWidget.h"
#include "ui_ParameterInfoWidget.h"

#include <QDebug>
#include <QMenu>
#include <QSqlQueryModel>
#include <QSqlTableModel>

ParameterInfoWidget::ParameterInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterInfoWidget)
{
    ui->setupUi(this);

    QHeaderView *headerView = ui->tableView->horizontalHeader();
    headerView->setContextMenuPolicy(Qt::CustomContextMenu);

    bool isConnected = false;  Q_UNUSED(isConnected);
    isConnected = connect(headerView, SIGNAL(customContextMenuRequested(QPoint)),
                          this, SLOT(showContextMenu(QPoint)));
    Q_ASSERT(isConnected);


}

ParameterInfoWidget::~ParameterInfoWidget()
{
    delete ui;
}

void ParameterInfoWidget::update()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("qry_paramsimple");
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("A"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

//    QSqlQueryModel *model = new QSqlQueryModel(this);
//    model->setQuery("SELECT * FROM qry_paramsimple");

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
}

void ParameterInfoWidget::showContextMenu(QPoint point)
{
    qDebug() << "Shoe Menu";
    QPoint p = ui->tableView->viewport()->mapToGlobal(point);

    QMenu contextMenu(this);

    QAction action1("Do something", this);
    //connect(&action1, SIGNAL(triggered()), this, SLOT(removeDataPoint()));
    contextMenu.addAction(&action1);

    contextMenu.exec(p);
}

