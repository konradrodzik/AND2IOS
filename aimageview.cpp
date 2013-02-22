#include "aimageview.h"

AImageView::AImageView()
{
}

void AImageView::read(QDomNode &element)
{
    AView::read(element);

    QDomElement e = element.toElement();
    QString srcName = e.attribute("src");
    // srcName = srcName.split('/');
    if(!srcName.isEmpty()) {
        // srcName
    }
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UIImageView alloc] initWithImage:[UIImage imageNamed@]];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;

}
