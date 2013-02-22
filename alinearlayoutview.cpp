#include "alinearlayoutview.h"

ALinearLayoutView::ALinearLayoutView()
{
}

void ALinearLayoutView::read(QDomNode &element)
{
    ALayoutView::read(element);

    QDomElement e = element.toElement();

    posX = QString::number(atof(qPrintable(e.attribute("android:paddingLeft"))));
    posY = QString::number(atof(qPrintable(e.attribute("android:paddingTop"))));

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
}

void ALinearLayoutView::write(QTextStream &writer, const QString &parentControlName)
{
    ALayoutView::write(writer, parentControlName);
    writer << varName() << "= [[UIView alloc] initWithFrame:CGRectZero];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << varName() << ".userInteractionEnabled = YES;" << endl;

    if (backgroundColor.length() > 0) {
        writer << "[" << varName() << " setBackgroundColor:" << "[UIColor colorWithRed:" << br << " green:" << bg << " blue:" << bb << " alpha:" << ba << "]];" << endl;
    }

    if (posX.length() > 0 && posY.length() > 0) {
        writer << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;
    } else if (parentControlName.length() > 0) {
        writer << varName() << ".frame = " << parentControlName << ".frame;" << endl;
    } else {
        writer << varName() << ".frame = self.bounds;";
    }

}
