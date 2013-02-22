#include "aview.h"

AView::AView()
{
}

QString AView::className()
{
    return "UIView";
}

QString AView::varName()
{
    char buf[66];
    sprintf(buf, "var_%08x", p);
    return buf;
}

void AView::read(QDomElement &element)
{
}

void AView::write(QTextStream &writer, const QString &parentControlName)
{
}
