//===============================================
#include "GStyle.h"
#include "GGraphView.h"
#include "GMessageView.h"
#include "GProcess.h"
#include <QApplication>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    GStyle::Instance()->load();
    GGraphView::Instance()->show();
    GMessageView::Instance()->show();
    GProcess::Instance()->run();
    return app.exec();
}
//===============================================
