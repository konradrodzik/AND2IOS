#include "atextview.h"

ATextView::ATextView()
{
}

void ATextView::write(QTextStream& writer, const QString& parentControlName)
{
    AView::write(writer, parentControlName);
    writer << varName() << " = [UILabel alloc] initWithRect:CGRectZero];" << endl
           << "[" << varName() << " setBackgroundColor:" << backgroundColor << "];" << endl
           << "[" << varName() << " setColor:" << color << "];" << endl
           << "[" << varName() << " setText:@\"" << text << "\"];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << " setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;
}
