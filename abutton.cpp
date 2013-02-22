#include "abutton.h"

AButton::AButton()
{
}

void AButton::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UIButton buttonWithType:UIButtonTypeCustom];\n";
    writer << varName() << ".frame = CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ");\n";
    if (text.length() > 0)
    {
        writer << "[" << varName() << " setTitle:@\"" << text << "\" forState:UIControlStateNormal];\n";
    }

    if (imageName.length() > 0)
    {
        writer << "[" << varName() << " setImage:[UIImage imageNamed:@\"" << imageName << "\"] forState:UIControlStateNormal];\n";
    }

    if (backgroundImageName.length() > 0)
    {
        writer << "[" << varName() << " setBackgroundImage:[UIImage imageNamed:@\"" << backgroundImageName << "\"] forState:UIControlStateNormal];\n";
    }

    if (onClickMethodName.length() > 0)
    {
        writer << "[" << varName() << " addTarget:self action:@selector(" << onClickMethodName << ":) forControlEvents:UIControlEventTouchUpInside];\n";
    }

    wrtier << "[" << parentControlName << " addSubview:" << varName() << "]\n";
}
