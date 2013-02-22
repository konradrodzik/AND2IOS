#include "aimageview.h"

AImageView::AImageView()
{
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UIImageView alloc] initWithImage:[UIImage imageNamed@]];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "]" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")]" << endl;

}
