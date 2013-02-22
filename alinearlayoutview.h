#ifndef ALINEARLAYOUTVIEW_H
#define ALINEARLAYOUTVIEW_H

#include "alayoutview.h"

class ALinearLayoutView : public ALayoutView
{
public:
    ALinearLayoutView();
    virtual void read(QDomElement& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ALINEARLAYOUTVIEW_H
