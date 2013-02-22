#include "alayoutview.h"

ALayoutView::ALayoutView()
{
}

void ALayoutView::read(QDomNode &element)
{
}

void ALayoutView::write(QTextStream &writer, const QString &parentControlName)
{
    writer << varName() << "= [UIView alloc] initWithRect:CGRectZero];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "]" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")]" << endl;

}
