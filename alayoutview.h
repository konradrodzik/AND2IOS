#ifndef ALAYOUTVIEW_H
#define ALAYOUTVIEW_H

#include "aview.h"

class ALayoutView : public AView
{
public:
    ALayoutView();
    virtual void read(QDomElement& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ALAYOUTVIEW_H
