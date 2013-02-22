#ifndef ALAYOUTFILE_H
#define ALAYOUTFILE_H

#include "aview.h"

class ALayoutFile : public AView
{
public:
  ALayoutFile();
  QString varName() { return "self"; }
  virtual void read(QDomNode& element);

  virtual void writeHeader(QTextStream& writer);
  virtual void writeSource(QTextStream& writer);
};

#endif // ALAYOUTFILE_H
