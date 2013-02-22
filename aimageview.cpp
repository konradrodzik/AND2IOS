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

    posX = QString::number(e.attribute("android:paddingLeft").toFloat());
    posY = QString::number(e.attribute("android:paddingTop").toFloat());
    width = "0";
    height = "0";
}

void AImageView::write(QTextStream& writer, const QString& parentControlName)
{
    AView::write(writer, parentControlName);
    writer << varName() << "= [[UIImageView alloc] initWithFrame:CGRectZero];" << endl
           << "[" << parentControlName << " addSubview:" << varName() << "];" << endl
           << "[" << varName() << " setFrame:CGRectMake(" << posX << ", " << posY << ", " << width << ", " << height << ")];" << endl;



    if(!srcImage.isEmpty() && !srcFileName.isEmpty()) {
        QFile outputFile(outputDir.absoluteFilePath(srcFileName));
        if(outputFile.open(QFile::WriteOnly)) {
            outputFile.write(srcImage);
        }

        writer << "[" << varName() << " setImage:[UIImage imageNamed:@\"" << src  << "\"]];" << endl;
    }

    writer << "[" << parentControlName << " addSubview:" <<varName() << "];" << endl;
}
