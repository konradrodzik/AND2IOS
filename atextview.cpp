#include "atextview.h"

ATextView::ATextView()
{
}

void ATextView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UILabel alloc] initWithRect:CGRectZero];\n"
           << "[" << varName() << " setBackgroundColor:" << backgroundColor << "]\n"
           << "[" << varName() << " setColor:" << color << "]\n"
           << "[" << varName() << "setText:@\"" << text << "\"]\n"
           << "[" << parentControlName << " addSubview:" << varName() << "]\n";
}
