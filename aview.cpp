#include "aview.h"
#include "alayoutfile.h"

AView::AView()
{
  parent = NULL;
}

QString AView::className()
{
    return "UIView";
}

QString AView::varName()
{
    if(!id.isEmpty())
        return id;
    char buf[66];
    sprintf(buf, "var_%08x", this);
    return buf;
}

void AView::read(QDomNode &element)
{
  QDomNodeList nodeList = element.childNodes();

  for(int i = 0; i < nodeList.count(); ++i) {
    QDomNode node = nodeList.item(i);
    if(!node.isElement())
      continue;
    QDomElement element = node.toElement();

    QString name = node.nodeName();
    AView* newView = createView(name, this);
    if(!newView)
      continue;
    childs.append(newView);
    newView->read(element);
  }

    QDomElement e = element.toElement();
    id = e.attribute("android:id");
    id = explodeName(id);
    id = captializeName(id);

    width = QString::number(atof(qPrintable(e.attribute("android:layout_width"))));
    height = QString::number(atof(qPrintable(e.attribute("android:layout_height"))));
}

void AView::write(QTextStream &writer, const QString &parentControlName)
{
}

void AView::writeSource(QTextStream &writer)
{
}

ALayoutFile *AView::file() const
{
    AView* p = const_cast<AView*>(this);
    while(p) {
        if(dynamic_cast<ALayoutFile*>(p)) {
            return reinterpret_cast<ALayoutFile*>(p);
        }
        p = p->parent;
    }
    return NULL;
}

QList<AView *> AView::allChilds()
{
  QList<AView*> otherChilds = childs;
  foreach(AView* child, childs)
    otherChilds.append(child->allChilds());
  return otherChilds;
}

void AView::writeHeader(QTextStream &writer)
{
}
