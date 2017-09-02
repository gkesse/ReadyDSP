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
void GGraphView::run() {
    QVector<double> x(101), y(101);
    for (int i=0; i<101; ++i) {
      x[i] = i/50.0 - 1;
      y[i] = x[i]*x[i];
    }

    ui->m_graph->addGraph();
    ui->m_graph->graph(0)->setData(x, y);
    ui->m_graph->xAxis->setRange(-1, 1);
    ui->m_graph->yAxis->setRange(0, 1);
    ui->m_graph->replot();
}
//===============================================

