#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QtXml>

#include "aview.h"
#include "alayoutfile.h"
#include "alayoutview.h"
#include "alinearlayoutview.h"
#include "atextview.h"

AView *AView::createView(const QString &name)
{
  if(name == "View")
    return new AView;
  if(name == "LinearLayout")
    return new ALinearLayoutView;
  if(name == "TextView")
    return new ATextView;
  return NULL;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList layouts = QDir::current().entryList(QStringList("layout/*.xml"));

    QList<ALayoutFile*> files;

    foreach(QString fileName, layouts) {
      QDomDocument doc;
      QFile file(fileName);
      if(!file.open(QFile::ReadOnly))
        continue;
      doc.setContent(&file);

      QDomElement element = doc.firstChildElement();
      if(element.isNull())
        continue;

      ALayoutFile* layoutFile = new ALayoutFile;
      layoutFile->read(element);
    }

    // generate code
    // here
    
    return a.exec();
}



int aaaa() {

    // TextView ->UILabel
    // Parameters: objectName,parentName

//    UILabel* %s = [UILabel alloc] initWithRect:CGRectZero];
//    [%s setBackgroundColor:[UIColor clear]];
//    [%s setColor:[UIColor redColor]];
//    [%s addSubview:%s];


  return 0;
}

