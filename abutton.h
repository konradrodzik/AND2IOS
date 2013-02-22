#ifndef ABUTTON_H
#define ABUTTON_H

#include <QString>

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
};

#endif // ABUTTON_H
