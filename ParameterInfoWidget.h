#ifndef PARAMETERINFOWIDGET_H
#define PARAMETERINFOWIDGET_H

#include <QWidget>

class ParameterInfoWidgetPrivate;

namespace Ui {
class ParameterInfoWidget;
}

class ParameterInfoWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ParameterInfoWidget)

public:
    explicit ParameterInfoWidget(QWidget *parent = 0);
    ~ParameterInfoWidget();

    void update();

private slots:

private:
    Ui::ParameterInfoWidget *ui;

    ParameterInfoWidgetPrivate* d_ptr;
};

#endif // PARAMETERINFOWIDGET_H
