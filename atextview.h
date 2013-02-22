#ifndef ATEXTVIEW_H
#define ATEXTVIEW_H

#include "aview.h"

class ATextView : public AView
{
public:
    QString text;
    QString tr,tg,tb,ta;
public:
    ATextView();
    QString className() { return "UILabel"; }
    void write(QTextStream& writer, const QString& parentControlName);
    virtual void read(QDomNode& element);
};

#endif // ATEXTVIEW_H
