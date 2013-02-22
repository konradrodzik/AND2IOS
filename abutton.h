#ifndef ABUTTON_H
#define ABUTTON_H

#include <QString>

#include "alayoutview.h"

class AButton : public ALayoutView
{
public:
    QString text;
    QString backgroundImageName;
    QString imageName;
    QString onClickMethodName;
public:
    AButton();
    QString className() { return "UIButton"; }
    void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ABUTTON_H