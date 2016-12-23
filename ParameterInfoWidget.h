#ifndef PARAMETERINFOWIDGET_H
#define PARAMETERINFOWIDGET_H

#include <QWidget>

namespace Ui {
class ParameterInfoWidget;
}

class ParameterInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterInfoWidget(QWidget *parent = 0);
    ~ParameterInfoWidget();

    void update();

private slots:
    void showContextMenu(QPoint point);

private:
    Ui::ParameterInfoWidget *ui;
};

#endif // PARAMETERINFOWIDGET_H
