//===============================================
#include "GGraphView.h"
#include "ui_GGraphView.h"
//===============================================
GGraphView* GGraphView::m_instance = 0;
//===============================================
GGraphView::GGraphView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GGraphView) {
    ui->setupUi(this);
    m_id = -1;
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
void GGraphView::setColor(const QBrush& color) {
    m_color = color;
}
//===============================================
void GGraphView::setData(const QVector<double>& x, const QVector<double>& y) {
    m_xData = x;
    m_yData = y;
}
//===============================================
void GGraphView::setXRange(const double& xMin, const double& xMax) {
    m_xMin = xMin;
    m_xMax = xMax;
}
//===============================================
void GGraphView::setYRange(const double& yMin, const double& yMax) {
    m_yMin = yMin;
    m_yMax = yMax;
}
//===============================================
void GGraphView::drawGraph() {
    ui->m_graph->addGraph();
    m_id++;
    ui->m_graph->graph(m_id)->setPen(QPen(m_color, 1));
    ui->m_graph->graph(m_id)->setData(m_xData, m_yData);
    ui->m_graph->xAxis->setRange(m_xMin, m_xMax);
    ui->m_graph->yAxis->setRange(m_yMin, m_yMax);
}
//===============================================
void GGraphView::drawSample() {
    for(int i = 0; i < m_xData.size(); i++) {
        QVector<double> m_xPt(2);
        QVector<double> m_yPt(2);
        m_xPt[0] = m_xData[i];
        m_xPt[1] = m_xData[i];
        m_yPt[0] = 0;
        m_yPt[1] = m_yData[i];
        ui->m_graph->addGraph();
        m_id++;
        ui->m_graph->graph(m_id)->setPen(QPen(m_color, 1));
        ui->m_graph->graph(m_id)->setData(m_xPt, m_yPt);
        ui->m_graph->xAxis->setRange(m_xMin, m_xMax);
        ui->m_graph->yAxis->setRange(m_yMin, m_yMax);
    }
}
//===============================================

