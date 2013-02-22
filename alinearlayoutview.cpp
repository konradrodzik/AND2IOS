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
    writer << varName() << "= [[UIView alloc] initWithRect:CGRectZero];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl;
    if (posX.length() > 0 && posY.length() > 0) {
        writer << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;
    } else if (parentControlName.length() > 0) {
        writer << varName() << ".frame = " << parentControlName << ".frame;" << endl;
    } else {
        writer << varName() << ".frame = self.bounds;";
    }

}
