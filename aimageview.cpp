#include "aimageview.h"

AImageView::AImageView()
{
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    AView::write(writer, parentControlName);
    writer << varName() << "= [UIImageView alloc] initWithImage:[UIImage imageNamed@]];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;

}

void AImageView::read(QDomNode &element)
{
    AView::read(element);
}
