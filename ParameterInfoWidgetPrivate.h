#ifndef PARAMETERINFOWIDGETPRIVATE_H
#define PARAMETERINFOWIDGETPRIVATE_H

#include "ParameterInfoWidget.h"

#include <QObject>

namespace Ui {
class ParameterInfoWidget;
}

class ParameterInfoWidgetPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(ParameterInfoWidget)

public:
    explicit ParameterInfoWidgetPrivate(ParameterInfoWidget *parent);

    void initialize(Ui::ParameterInfoWidget *parentUi);

    void update();

signals:

public slots:
private slots:
    void showContextMenu(QPoint point);

private:
    Ui::ParameterInfoWidget *_parentUi;
    ParameterInfoWidget* q_ptr;
};

#endif // PARAMETERINFOWIDGETPRIVATE_H
