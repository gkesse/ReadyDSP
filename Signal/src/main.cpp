//===============================================
#include "GSignal.h"
#include "GStyle.h"
#include "GGraphView.h"
#include "GMessageView.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GGraphView::Instance()->show();
    GMessageView::Instance()->show();
    return app.exec();
}
//===============================================
