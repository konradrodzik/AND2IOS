#include "atextview.h"

ATextView::ATextView()
{
}

void ATextView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << " = [[UILabel alloc] initWithFrame:CGRectZero];" << endl;
    if (backgroundColor.length() > 0) {
        writer << "[" << varName() << " setBackgroundColor:" << backgroundColor << "];" << endl;
    }

    if (color.length() > 0) {
        writer << "[" << varName() << " setColor:" << "[UIColor colorWithRed:" << tr << " green:" << tg << "blue:" << tb << " alpha:" << ta << "]]" << endl;
    }

    writer << "[" << varName() << " setText:@\"" << text << "\"];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << " setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;
}

void ATextView::read(QDomNode &element)
{
    AView::read(element);
    QDomElement e = element.toElement();

    color = e.attribute("android:textColor");
    if(color.length() > 0) {
        if(color.startsWith("#")) {
            QByteArray rgb = QByteArray::fromHex(color.mid(1).toLatin1());
            if(rgb.count() == 4) {
                ta = rgb[0];
                tr = rgb[1];
                tg = rgb[2];
                tb = rgb[3];
            }
        }
    }

    text = e.attribute("android:text");
    posX = e.attribute("android:paddingLeft");
    posY = e.attribute("android:paddingTop");
    width = "0";
    height = "0";
}
