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
  writer << "@interface " << name << " : UIView {" << endl;

  foreach(AView* child, allChilds()) {
      if(child->isLocal())
          continue;
    writer << "\t" << child->className() << " *" << child->varName() << ";" << endl;
  }

  writer << "}" << endl << endl;

  foreach(AView *child, allChilds()) {
      if(child->isLocal())
          continue;
      writer << "@property(nonatomic, readonly) " << child->className() << " *" << child->varName() << ";" << endl;
  }
  writer << endl;

  writer << "-(void)initWithFrame:(CGRect)rect;" << endl;
  writer << endl;
  writer << "@end" << endl << endl;
}

void ALayoutFile::writeSource(QTextStream &writer)
{
    writer << "@interface " << name << "()" << endl;
    foreach(AView *child, allChilds()) {
        if(child->isLocal())
            continue;
        writer << "@property(nonatomic, strong) " << child->className() << " *" << child->varName() << ";" << endl;
    }
    writer << "@end" << endl << endl;
    // XYZ: function prolog
    writer << "@implementation " << name << "{" << endl
         << "}" << endl;
    writer << endl;
    foreach(AView* child, allChilds()) {
        if(child->isLocal())
            continue;
        writer << "@synthesize " << child->varName() << ";" << endl;
    }

    writer << endl;

    writer << "-(id)init {" << endl
           << "\tif(self = [super init]) {" << endl;

    QByteArray data;

    {
        QTextStream newStream(&data);
        foreach(AView* child, allChilds()) {
            if(child->isLocal())
                newStream << child->className() << " *" << child->varName() << " = NULL;" << endl;
            child->write(newStream, child->parent->varName());
            newStream << endl;
        }
        newStream.flush();
    }

    {
        QTextStream newStream(&data);
        while(!newStream.atEnd()) {
            QString line = newStream.readLine();
            writer << "\t\t" << line << endl;
        }
    }

    writer << "    }" << endl
           << "    return self;" << endl
           << "}" << endl << endl;

    writer << "- (void)layoutSubviews {" << endl
           << "    [super layoutSubviews];" << endl;

    foreach(AView* child, allChilds()) {
        if (child->posX.length() > 0 && child->posY.length() > 0) {
            writer << "\t[" << child->varName() << "sizeToFit]" << endl;
            writer << "\t[" << child->varName() << " setFrame:CGRectMake(" << child->posX << ", " << child->posY << ", " << child->width << ", " << child->height << ")];" << endl;
        }
    }

    writer << "}" << endl << endl;

  // XYZ: function epilog

    writer << "@end";
}
