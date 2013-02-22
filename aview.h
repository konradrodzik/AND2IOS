#ifndef AVIEW_H
#define AVIEW_H

#include <QString>
#include <QList>
#include <QTextStream>
#include <QtXml>
#include <QDir>

extern QDir layoutDir;
extern QDir drawableDir;
extern QDir outputDir;

inline QString explodeName(QString name) {
    QStringList list = name.split('/');
    if(list.size() != 2)
        return QString();
    name = list[1];
    return name;
}

inline QString captializeName(QString name, bool firstCapital = false) {
    if(name.isEmpty())
        return QString();
    QString out;
    foreach(QString item, name.split('_', QString::SkipEmptyParts)) {
        if(out.isEmpty() && !firstCapital)
            out += item;
        else
            out += item[0].toUpper() + item.midRef(1).toString();
    }
    return out;
}

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
    virtual void read(QDomNode& element);
    virtual void write(QTextStream& writer, const QString& parentControlName);

    virtual QList<AView*> allChilds();
    bool isLocal() const {
        return id.isEmpty();
    }

public:
    static AView* createView(const QString& name, AView* view);
};

#endif // AVIEW_H
