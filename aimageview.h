#ifndef AIMAGEVIEW_H
#define AIMAGEVIEW_H

#include "atextview.h"

class AImageView : public AView
{
public:
    AImageView();

    QString className() { return "UIImageView"; }
    void write(QTextStream& writer, const QString& parentControlName);
    void read(QDomNode& element);
};

#endif // AIMAGEVIEW_H
