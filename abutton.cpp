#include "abutton.h"

AButton::AButton()
{
}

void AButton::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UIButton buttonWithType:UIButtonTypeCustom];\n"
           << "[" << varName() << " setBackgroundColor:" << backgroundColor << "];\n"
           << "[" << varName() << " setColor:" << color << "]\n"
           << "[" << varName() << "setText:@\"" << text << "\"]\n"
           << "[" << parentControlName << " addSubview:" << varName() << "]\n";
}
