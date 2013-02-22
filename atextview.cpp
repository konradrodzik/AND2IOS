#include "atextview.h"

ATextView::ATextView()
{
}

void ATextView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << " = [[UILabel alloc] initWithRect:CGRectZero];" << endl;
    if (backgroundColor.length() > 0) {
        writer << "[" << varName() << " setBackgroundColor:" << backgroundColor << "];" << endl;
    }

    if (color.length() > 0) {
        writer << "[" << varName() << " setColor:" << color << "];" << endl;
    }
    writer << "[" << varName() << " setText:@\"" << text << "\"];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << " setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;
}

void ATextView::read(QDomNode &element)
{
    AView::read(element);
    QDomElement e = element.toElement();

    text = e.attribute("android:text");
    posX = e.attribute("android:paddingLeft");
    posY = e.attribute("android:paddingTop");
    width = "0";
    height = "0";
}
