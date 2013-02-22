#ifndef ALINEARLAYOUTVIEW_H
#define ALINEARLAYOUTVIEW_H

#include "alayoutview.h"

class ALinearLayoutView : public ALayoutView
{
public:
    QString br,bg,bb,ba;
public:
    ALinearLayoutView();
    virtual void read(QDomNode& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ALINEARLAYOUTVIEW_H
