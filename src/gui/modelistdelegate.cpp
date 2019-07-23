#include "modelistdelegate.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QDebug>

void ModeListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //qDebug() << "paint";
    //qDebug() << index.model()->
    QStyledItemDelegate::paint(painter, option, index);
}
