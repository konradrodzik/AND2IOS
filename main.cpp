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
QDir outputDir;

#define NAME_PREFIX "and2ios"
#define HEADER_NAME NAME_PREFIX ".h"
#define SOURCE_NAME NAME_PREFIX ".m"

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
    drawableDir.cd("res/drawable-hdpi");

    outputDir = QDir::current();
    outputDir.mkdir("output");
    outputDir.cd("output");

    QList<ALayoutFile*> layouts;

    foreach(QString fileName, layoutDir.entryList(QStringList("*.xml"))) {
      QDomDocument doc;
      QFile file(layoutDir.absoluteFilePath(fileName));
      if(!file.open(QFile::ReadOnly))
        continue;
      doc.setContent(&file);

      ALayoutFile* layoutFile = new ALayoutFile;
      layoutFile->name = captializeName(QFileInfo(fileName).baseName(), true);
      layoutFile->read(doc);
      layouts.append(layoutFile);
    }

    QFile outputHeaderFile(outputDir.absoluteFilePath(HEADER_NAME));
    outputHeaderFile.open(QFile::WriteOnly);
    QTextStream outputHeader(&outputHeaderFile);

    QFile outputSourceFile(outputDir.absoluteFilePath(SOURCE_NAME));
    outputSourceFile.open(QFile::WriteOnly);
    QTextStream outputSource(&outputSourceFile);

    outputHeader << "#include <UIView.h>" << endl << endl;
    outputSource << "#include \"" << HEADER_NAME << "\"" << endl << endl;

    foreach(ALayoutFile* file, layouts) {
      file->writeHeader(outputHeader);
      file->writeSource(outputSource);
    }

    return 0;
}

