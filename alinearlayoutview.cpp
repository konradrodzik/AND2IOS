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
    ALayoutView::write(writer, parentControlName);
    writer << varName() << "= [UIView alloc] initWithRect:CGRectZero];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;

}
