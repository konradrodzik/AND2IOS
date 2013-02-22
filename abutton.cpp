#include "abutton.h"
#include <QTextStream>

AButton::AButton()
{
}

void AButton::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << " = [UIButton buttonWithType:UIButtonTypeCustom];" << endl;
    writer << varName() << ".frame = CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ");" << endl;
    if (text.length() > 0)
    {
        writer << "[" << varName() << " setTitle:@\"" << text << "\" forState:UIControlStateNormal];" << endl;
    }

    if (imageName.length() > 0)
    {
        writer << "[" << varName() << " setImage:[UIImage imageNamed:@\"" << imageName << "\"] forState:UIControlStateNormal];" << endl;
    }

    if (backgroundImageName.length() > 0)
    {
        writer << "[" << varName() << " setBackgroundImage:[UIImage imageNamed:@\"" << backgroundImageName << "\"] forState:UIControlStateNormal];" << endl;
    }

    if (onClickMethodName.length() > 0)
    {
        writer << "[" << varName() << " addTarget:self action:@selector(" << onClickMethodName << ":) forControlEvents:UIControlEventTouchUpInside];" << endl;
    }

    writer << "[" << parentControlName << " addSubview:" << varName() << "];" << endl;
}

void AButton::read(QDomNode &element)
{
    AView::read(element);
    QDomElement e = element.toElement();

    text = e.attribute("android:text");
    posX = QString::number(e.attribute("android:paddingLeft").toFloat());
    posY = QString::number(e.attribute("android:paddingTop").toFloat());
    width = "0";
    height = "0";
    onClickMethodName = e.attribute("android:onClick");
    backgroundImageName = e.attribute("android:background");
}

void AButton::writeSource(QTextStream &writer)
{
    if(onClickMethodName.size()) {
        writer << "-(void) " << onClickMethodName << ":(id)sender {" << endl;
        writer << "\tNSLog(@\"" << onClickMethodName << " clicked\");" << endl;
        writer << "}" << endl;
        writer << endl;
    }
}


void AButton::writeHeader(QTextStream &writer)
{
    if(onClickMethodName.size()) {
        writer << "-(void) " << onClickMethodName << ":(id)sender;";
    }
}
