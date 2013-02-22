#ifndef ALAYOUTVIEW_H
#define ALAYOUTVIEW_H

#include "aview.h"

class ALayoutView : public AView
{
public:
    ALayoutView();
    QString className() { return "UILayoutView"; }
};

#endif // ALAYOUTVIEW_H
