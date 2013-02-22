#ifndef AVIEW_H
#define AVIEW_H

#include <QString>
#include <QList>
#include <QTextStream>
#include <QtXml>

class AView
{
public:
    QString id;
    QString width, height;
    QString posX,posY;
    QList<AView*> childs;
    QString backgroundColor;
    QString color;
    AView* parent;

public:
    AView();
    virtual QString className();
    virtual QString varName();
    virtual void read(QDomElement& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);

    virtual QList<AView*> allChilds();

public:
    static AView* createView(const QString& name, AView* view);
};

#endif // AVIEW_H
