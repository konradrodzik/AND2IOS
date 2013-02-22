#ifndef ABUTTON_H
#define ABUTTON_H

#include <QString>
#include "aview.h"

#include "atextview.h"

class AButton : public ATextView
{
public:
    QString backgroundImageName;
    QString imageName;
    QString onClickMethodName;
public:
    AButton();
    QString className() { return "UIButton"; }
    void write(QTextStream& writer, const QString& parentControlName);
    void read(QDomNode& element);
    void writeSource(QTextStream& writer);
    void writeHeader(QTextStream& writer);
};

#endif // ABUTTON_H
