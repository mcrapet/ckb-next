#include <QUuid>
#include "modelistwidget.h"
#include <QHeaderView>
#include <QDebug>
#include <QTableWidgetItem>
#include <QDropEvent>
#include "modelisttablemodel.h"

ModeListWidget::ModeListWidget(QWidget *parent) :
    QTableView(parent), device(nullptr)
{
    connect(this, &QTableView::entered, this, [this](const QModelIndex& index){
        dynamic_cast<ModeListTableModel*>(model())->setHighlightedRow(index.row());
    });
}

void ModeListWidget::setDevice(Kb* dev){
    setModel(new ModeListTableModel(dev, this));
    device = dev;
    QHeaderView* const hh = horizontalHeader();
    hh->setSectionResizeMode(ModeListTableModel::COL_MODE_ICON, QHeaderView::ResizeToContents);
    hh->setSectionResizeMode(ModeListTableModel::COL_MODE_NAME, QHeaderView::Stretch);
    hh->setSectionResizeMode(ModeListTableModel::COL_EVENT_ICON, QHeaderView::ResizeToContents);
}

void ModeListWidget::leaveEvent(QEvent* event)
{
    dynamic_cast<ModeListTableModel*>(model())->setHighlightedRow(-1);
    QTableView::leaveEvent(event);
}
