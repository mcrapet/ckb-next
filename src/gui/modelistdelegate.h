#ifndef MODELISTDELEGATE_H
#define MODELISTDELEGATE_H
#include <QStyledItemDelegate>

class ModeListDelegate : public QStyledItemDelegate
{
public:
    explicit ModeListDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) {}
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MODELISTDELEGATE_H
