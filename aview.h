#ifndef AVIEW_H
#define AVIEW_H

#include <QString>
#include <QList>
#include <QTextStream>
#include <QtXml>
#include <QDir>

extern QDir layoutDir;
extern QDir drawableDir;

inline QString explodeName(QString name) {
    QStringList list = name.split('/');
    if(list.size() != 2)
        return QString();
    name = list[1];
    return name;
}

inline QString captializeName(QString name) {
    // QString out = QString();
	return QString();
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

public:
    static AView* createView(const QString& name, AView* view);
};

#endif // AVIEW_H
