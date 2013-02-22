#include "atextview.h"

ATextView::ATextView()
{
}

void ATextView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << " = [[UILabel alloc] initWithFrame:CGRectZero];" << endl;

    if (color.length() > 0) {
        writer << "[" << varName() << " setTextColor:" << "[UIColor colorWithRed:" << tr << " green:" << tg << " blue:" << tb << " alpha:" << ta << "]];" << endl;
    }

    if (backgroundColor.length() > 0) {
        writer << "[" << varName() << " setBackgroundColor:" << "[UIColor colorWithRed:" << br << " green:" << bg << " blue:" << bb << " alpha:" << ba << "]];" << endl;
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
                ta = QString::number(((unsigned char)rgb[0]) / 255.0f);
                tr = QString::number(((unsigned char)rgb[1]) / 255.0f);
                tg = QString::number(((unsigned char)rgb[2]) / 255.0f);
                tb = QString::number(((unsigned char)rgb[3]) / 255.0f);
            }
        }
    }

    backgroundColor = e.attribute("android:background");
    if(backgroundColor.length() > 0) {
        if(backgroundColor.startsWith("#")) {
            QByteArray rgb = QByteArray::fromHex(backgroundColor.mid(1).toLatin1());
            if(rgb.count() == 4) {
                ba = QString::number(((unsigned char)rgb[0]) / 255.0f);
                br = QString::number(((unsigned char)rgb[1]) / 255.0f);
                bg = QString::number(((unsigned char)rgb[2]) / 255.0f);
                bb = QString::number(((unsigned char)rgb[3]) / 255.0f);
            }
        }
    }

    text = e.attribute("android:text");
    posX = QString::number(atof(qPrintable(e.attribute("android:layout_marginLeft"))));
    posY = QString::number(atof(qPrintable(e.attribute("android:layout_marginTop"))));
    width = "0";
    height = "0";
}
