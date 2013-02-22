#include "alayoutfile.h"

ALayoutFile::ALayoutFile()
{

}

void ALayoutFile::read(QDomElement &element)
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
    writer << "@implementation " << varName() << "{" << endl
         << "}" << endl;
    foreach(AView* child, allChilds()) {
        writer << "@synthesize" << child->varName() << ";" << endl;
    }

    writer << endl;

    writer << "-(id)init {" << endl
           << "    if(self = [super init]) {" << endl;
    foreach(AView* child, allChilds()) {
        child->write(writer, child->parent->varName());
        writer << endl;
    }
    writer << "    " << endl
           << "    return self;" << endl
           << "}" << endl << endl;

    writer << "- (void)layoutSubviews {" << endl
           << "    [super layoutSubviews];" << endl;

    foreach(AView* child, allChilds()) {
        writer << "[" << child->varName() << "setFrame:CGRectMake(" << child->posX << ", " << child->posY << ", " << child->width << ", " << child->height << ")];" << endl;
    }

    writer << "}" << endl << endl;

  // XYZ: function epilog

    writer << "@end";
}
