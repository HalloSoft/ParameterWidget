#include "ParameterInfoWidget.h"
#include "ParameterInfoWidgetPrivate.h"
#include "ui_ParameterInfoWidget.h"

#include <QDebug>
#include <QMenu>
#include <QSqlQueryModel>
#include <QSqlTableModel>

ParameterInfoWidget::ParameterInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterInfoWidget),
    d_ptr(new ParameterInfoWidgetPrivate(this))
{
    Q_D(ParameterInfoWidget);

    d->initialize(ui);
}

ParameterInfoWidget::~ParameterInfoWidget()
{
    delete ui;
}

void ParameterInfoWidget::update()
{
    Q_D(ParameterInfoWidget);

    d->update();
}





