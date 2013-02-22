#include <QCoreApplication>

/*

  // interface
  @interface activity_layout_main  {
   // fields
   iosClassName* id;
  }

  // methods
  -(void)initWithFrame:(CGRect)rect;
  -(void)setupUi;
  -(void)testme;

  @end


  -(void)setupUi()
  {
  id = [[UIView create...]]];

  }
  */

class AView
{
};

class ATextView : public AView
{
public:
};

class AButton : public ATextView
{
};

class ALayoutView : public AView
{
public:
    QString layout_width, layout_height;
};

class ALinearLayoutView : public ALayoutView
{
public:
    QString orientation;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    return a.exec();
}
