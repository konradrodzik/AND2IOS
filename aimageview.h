#ifndef AIMAGEVIEW_H
#define AIMAGEVIEW_H

#include "atextview.h"

class AImageView : AView
{
public:
    AImageView();

    QString className() { return "UIImageView"; }
    void write(QTextStream& writer, const QString& parentControlName);
};

#endif // AIMAGEVIEW_H
