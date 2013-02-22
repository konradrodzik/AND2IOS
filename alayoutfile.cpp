#include "alayoutfile.h"

ALayoutFile::ALayoutFile()
{

}

void ALayoutFile::read(QDomNode &element)
{
  AView::read(element);
}

void ALayoutFile::writeHeader(QTextStream &writer)
{
  writer << "@interface " << varName() << " : UIView {" << endl;

  foreach(AView* child, allChilds()) {
    writer << "\t" << child->className() << " *" << child->varName() << endl;
  }

  writer << "}" << endl << endl;
  writer << "-(void)initWithFrame:(CGRect)rect;" << endl;
  writer << "@end" << endl << endl;
}

void ALayoutFile::writeSource(QTextStream &writer)
{
  // XYZ: function prolog

  foreach(AView* child, allChilds()) {
    child->write(writer, child->parent->varName());
  }

  // XYZ: function epilog
}
