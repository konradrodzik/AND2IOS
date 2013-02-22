#ifndef ALAYOUTFILE_H
#define ALAYOUTFILE_H

#include "aview.h"

class ALayoutFile : public AView
{
public:
  ALayoutFile();
  virtual void read(QDomElement& element);
};

#endif // ALAYOUTFILE_H
