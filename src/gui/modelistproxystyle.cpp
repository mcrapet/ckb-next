#include "modelistproxystyle.h"
#include <QProxyStyle>
#include <QDebug>

void ModeListProxyStyle::drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    qDebug() << "Draw primitive";
    QProxyStyle::drawPrimitive(element, option, painter, widget);
}
