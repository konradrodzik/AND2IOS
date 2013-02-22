#ifndef AIMAGEVIEW_H
#define AIMAGEVIEW_H

#include "atextview.h"

class AImageView : public AView
{
public:
    QString src;
    QByteArray srcImage;

public:
    AImageView();

    QString className() { return "UIImageView"; }
    void read(QDomNode& element);
    void write(QTextStream& writer, const QString& parentControlName);
    void read(QDomNode& element);
};

#endif // AIMAGEVIEW_H
