//===============================================
#include "GGraphView.h"
#include "GStyle.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GGraphView::Instance()->run();
    GGraphView::Instance()->show();
    return app.exec();
}
//===============================================
