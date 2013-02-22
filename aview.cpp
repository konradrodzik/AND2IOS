#include "aview.h"

AView::AView()
{
}

QString AView::className()
{
    return "UIView";
}

QString AView::varName()
{
    char buf[66];
    sprintf(buf, "var_%08x", this);
    return buf;
}

void AView::read(QDomElement &element)
{
  QDomNodeList nodeList = element.childNodes();

  for(int i = 0; i < nodeList.count(); ++i) {
    QDomNode node = nodeList.item(i);
    if(!node.isElement())
      continue;
    QDomElement element = node.toElement();

    QString name = node.nodeName();
    AView* newView = createView(name);
    if(!newView)
      continue;
    childs.append(newView);
    newView->read(element);
  }
}

void AView::write(QTextStream &writer, const QString &parentControlName)
{

}
