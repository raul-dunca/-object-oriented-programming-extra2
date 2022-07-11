#include "QtWidgetsApplication8.h"
#include <QtWidgets/QApplication>
#include "QtWidgetsClass.h"
#include "Test.h"
int main(int argc, char *argv[])
{
    test();
    QApplication a(argc, argv);
    Repo r;
    Service s{ r };
    ProductsModel* model = new ProductsModel{ s };
    for (auto a : s.get_writers_serv())
    {
        QtWidgetsClass* w = new QtWidgetsClass{ a,model };
        w->show();
    }
    return a.exec();
}
