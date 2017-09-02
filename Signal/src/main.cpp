//===============================================
#include "GSignal.h"
#include "GStyle.h"
#include "GGraphView.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GGraphView::Instance()->show();
    return app.exec();
}
//===============================================
