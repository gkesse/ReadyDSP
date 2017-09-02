//===============================================
#include "GMessageView.h"
#include "GStyle.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GMessageView::Instance()->showData("Hello World!");
    return app.exec();
}
//===============================================
