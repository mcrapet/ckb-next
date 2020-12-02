#ifndef MODELISTWIDGET_H
#define MODELISTWIDGET_H

#include <QTableView>
#include <QTimer>
#include "kb.h"

class ModeListWidget : public QTableView
{
    Q_OBJECT
public:
    explicit ModeListWidget(QWidget *parent = 0);
    void setDevice(Kb* dev);

signals:
    void orderChanged();

private:
    void leaveEvent(QEvent* event);
    Kb* device;
};

#endif // MODELISTWIDGET_H
