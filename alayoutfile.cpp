#include "alayoutfile.h"

ALayoutFile::ALayoutFile()
{

}

void ALayoutFile::read(QDomElement &element)
{
  AView::read(element);
}
