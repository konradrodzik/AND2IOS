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
    QList<AView*> childs;

public:
    AView();
    virtual QString className();
    virtual QString varName();
    virtual void read(QDomElement& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);

public:
    static AView* createView(const QString& name);
};

#endif // AVIEW_H
