#ifndef AIMAGEVIEW_H
#define AIMAGEVIEW_H

#include "atextview.h"

class AImageView : public AView
{
public:
    QString src;
    QString srcFileName;
    QByteArray srcImage;

public:
    AImageView();

    QString className() { return "UIImageView"; }
    void read(QDomNode& element);
    void write(QTextStream& writer, const QString& parentControlName);
};

#endif // AIMAGEVIEW_H
