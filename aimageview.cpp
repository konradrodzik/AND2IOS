#include "aimageview.h"

AImageView::AImageView()
{
}

void AImageView::read(QDomNode &element)
{
    AView::read(element);

    QDomElement e = element.toElement();

    src = e.attribute("android:src");
    src = explodeName(src);

    if(!src.isEmpty()) {
        srcFileName = src + ".png";

        QFile file(drawableDir.absoluteFilePath(srcFileName));

        if(file.open(QFile::ReadOnly))
            srcImage = file.readAll();
        else
            src.clear();
    }
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    writer << varName() << "= [UIImageView alloc] initWithImage:[UIImage imageNamed@]];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << "setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;

    if(!srcImage.isEmpty() && !srcFileName.isEmpty()) {
        QFile outputFile(outputDir.absoluteFilePath(srcFileName));
        if(outputFile.open(QFile::WriteOnly)) {
            outputFile.write(srcImage);
        }
    }
}
