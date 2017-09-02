//===============================================
#include "GGraphView.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GGraphView::Instance()->show();
    return app.exec();
}
//===============================================
