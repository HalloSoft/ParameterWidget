#include "ParameterInfoWidgetPrivate.h"
#include "ui_ParameterInfoWidget.h"

#include <QDebug>
#include <QMenu>
#include <QSqlQueryModel>
#include <QSqlTableModel>

ParameterInfoWidgetPrivate::ParameterInfoWidgetPrivate(ParameterInfoWidget *parent) :
    QObject(parent),
    q_ptr(parent)
{

}

void ParameterInfoWidgetPrivate::initialize(Ui::ParameterInfoWidget *parentUi)
{
    Q_Q(ParameterInfoWidget);

    _parentUi = parentUi;
    Q_CHECK_PTR(_parentUi);

    parentUi->setupUi(q);

    QHeaderView *headerView = _parentUi->tableView->horizontalHeader();
    headerView->setContextMenuPolicy(Qt::CustomContextMenu);

    bool isConnected = false;  Q_UNUSED(isConnected);
    isConnected = connect(headerView, SIGNAL(customContextMenuRequested(QPoint)),
                          this, SLOT(showContextMenu(QPoint)));
    Q_ASSERT(isConnected);

}

void ParameterInfoWidgetPrivate::showContextMenu(QPoint point)
{
    Q_Q(ParameterInfoWidget);

    qDebug() << "Shoe Menu";
    QPoint p = _parentUi->tableView->viewport()->mapToGlobal(point);

    QMenu contextMenu(q);

    QAction action1("Do something", this);
    //connect(&action1, SIGNAL(triggered()), this, SLOT(removeDataPoint()));
    contextMenu.addAction(&action1);

    contextMenu.exec(p);
}

void ParameterInfoWidgetPrivate::update()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("qry_paramsimple");
    model->select();
    //model->setHeaderData(0, Qt::Horizontal, tr("A"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

//    QSqlQueryModel *model = new QSqlQueryModel(this);
//    model->setQuery("SELECT * FROM qry_paramsimple");

    _parentUi->tableView->setModel(model);
    //_parentUi->tableView->hideColumn(0);
}
