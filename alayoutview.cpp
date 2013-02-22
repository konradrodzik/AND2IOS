#include "alayoutview.h"

ALayoutView::ALayoutView()
{
}

void ALayoutView::read(QDomNode &element)
{
    AView::read(element);
}

void ALayoutView::write(QTextStream &writer, const QString &parentControlName)
{
}
