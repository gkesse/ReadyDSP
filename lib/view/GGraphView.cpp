//===============================================
#include "GGraphView.h"
#include "ui_GGraphView.h"
//===============================================
GGraphView* GGraphView::m_instance = 0;
//===============================================
GGraphView::GGraphView(QWidget *parent) :
QWidget(parent), ui(new Ui::GGraphView) {
    ui->setupUi(this);
}
//===============================================
GGraphView::~GGraphView() {
    delete ui;
}
//===============================================
GGraphView* GGraphView::Instance() {
    if(m_instance == 0) {
        m_instance = new GGraphView;
    }
    return m_instance;
}
//===============================================
void GGraphView::closeEvent(QCloseEvent *event) {
    qApp->closeAllWindows();
    event->accept();
}
//===============================================
QCustomPlot* GGraphView::graph() const {
    return ui->m_graph;
}
//===============================================

