#ifndef ATEXTVIEW_H
#define ATEXTVIEW_H

#include "aview.h"

class ATextView : public AView
{
public:
    ATextView();
    QString className() { return "UITextView"; }
};

#endif // ATEXTVIEW_H
