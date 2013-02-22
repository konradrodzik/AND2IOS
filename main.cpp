#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QtXml>

#include "aview.h"
#include "alayoutfile.h"
#include "alayoutview.h"
#include "alinearlayoutview.h"
#include "atextview.h"

AView *AView::createView(const QString &name, AView* view)
{
  AView* newView;

  if(name == "View")
    newView = new AView;
  else if(name == "LinearLayout")
    newView = new ALinearLayoutView;
  else if(name == "TextView")
    newView = new ATextView;
  else
    newView = NULL;

  if(newView) {
    newView->parent = view;
  }
  return newView;
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

    QFile outputHeaderFile("views.h");
    outputHeaderFile.open(QFile::WriteOnly);
    QTextStream outputHeader(&outputHeaderFile);

    QFile outputSourceFile("views.m");
    outputSourceFile.open(QFile::WriteOnly);
    QTextStream outputSource(&outputSourceFile);

    outputHeader << "#include <UIView.h>" << endl << endl;
    outputSource << "#include \"views.h\"" << endl << endl;

    foreach(ALayoutFile* file, files) {
      file->writeHeader(outputHeader);
      file->writeSource(outputSource);
    }

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
