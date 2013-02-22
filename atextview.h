#ifndef ATEXTVIEW_H
#define ATEXTVIEW_H

#include "aview.h"

class ATextView : public AView
{
public:
    QString text;
public:
    ATextView();
    QString className() { return "UILabel"; }
    void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ATEXTVIEW_H
