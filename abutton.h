#ifndef ABUTTON_H
#define ABUTTON_H

#include <QString>
#include "aview.h"

class AButton : public AView
{
public:
    QString text;
    QString backgroundImageName;
    QString imageName;
    QString onClickMethodName;
public:
    AButton();
    QString className() { return "UIButton"; }
    virtual void write(QTextStream& writer, const QString& parentControlName);
};

#endif // ABUTTON_H
