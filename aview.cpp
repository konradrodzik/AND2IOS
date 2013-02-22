#include "aview.h"

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
}

void AView::write(QTextStream &writer, const QString &parentControlName)
{

}

QList<AView *> AView::allChilds()
{
  QList<AView*> otherChilds = childs;
  foreach(AView* child, childs)
    otherChilds.append(child->allChilds());
  return otherChilds;
}
