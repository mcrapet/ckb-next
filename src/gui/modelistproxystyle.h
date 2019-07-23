#ifndef MODELISTPROXYSTYLE_H
#define MODELISTPROXYSTYLE_H

#include <QObject>
#include <QProxyStyle>

class ModeListProxyStyle : public QProxyStyle
{
public:
    explicit ModeListProxyStyle(QStyle* style = nullptr) : QProxyStyle(style) {}
    void drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const;
};

#endif // MODELISTPROXYSTYLE_H
