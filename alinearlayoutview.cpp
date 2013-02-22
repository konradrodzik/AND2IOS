#include "alinearlayoutview.h"

ALinearLayoutView::ALinearLayoutView()
{
}

void ALinearLayoutView::read(QDomNode &element)
{
    ALayoutView::read(element);
}

void ALinearLayoutView::write(QTextStream &writer, const QString &parentControlName)
{

}
