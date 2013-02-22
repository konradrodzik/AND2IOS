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

    posX = e.attribute("android:paddingLeft");
    posY = e.attribute("android:paddingRight");
    width = "0";
    height = "0";
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    AView::write(writer, parentControlName);
    writer << varName() << "= [UIImageView alloc] initWithImage:[UIImage imageNamed@]];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;

}
