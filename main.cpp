#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QtXml>

#include "aview.h"
#include "alayoutfile.h"
#include "alayoutview.h"
#include "alinearlayoutview.h"
#include "atextview.h"
#include "abutton.h"
#include "aimageview.h"

QDir layoutDir;
QDir drawableDir;

AView *AView::createView(const QString &name, AView* view)
{
  AView* newView;

  if(name == "View")
    newView = new AView;
  else if(name == "LinearLayout")
    newView = new ALinearLayoutView;
  else if(name == "Button")
    newView = new AButton;
  else if(name == "TextView")
    newView = new ATextView;
  else if(name == "ImageView")
    newView = new AImageView;
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

    layoutDir = QDir::current();
    layoutDir.cd("res/layout");

    drawableDir = QDir::current();
    drawableDir.cd("res/drawable");

    QList<ALayoutFile*> layouts;

    foreach(QString fileName, layoutDir.entryList(QStringList("*.xml"))) {
      QDomDocument doc;
      QFile file(layoutDir.absoluteFilePath(fileName));
      if(!file.open(QFile::ReadOnly))
        continue;
      doc.setContent(&file);

      ALayoutFile* layoutFile = new ALayoutFile;
      layoutFile->id = QFileInfo(fileName).baseName();
      layoutFile->read(doc);
      layouts.append(layoutFile);
    }

    QFile outputHeaderFile("views.h");
    outputHeaderFile.open(QFile::WriteOnly);
    QTextStream outputHeader(&outputHeaderFile);

    QFile outputSourceFile("views.m");
    outputSourceFile.open(QFile::WriteOnly);
    QTextStream outputSource(&outputSourceFile);

    outputSource << "#import \"views.h\"" << endl << endl;

    foreach(ALayoutFile* file, layouts) {
      file->writeHeader(outputHeader);
      file->writeSource(outputSource);
    }

    return 0;
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
