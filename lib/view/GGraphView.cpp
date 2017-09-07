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
    ui->m_graph->graph()->setPen(QPen(m_color, 1));
    ui->m_graph->graph()->setData(m_xData, m_yData);
    ui->m_graph->xAxis->setRange(m_xMin, m_xMax);
    ui->m_graph->yAxis->setRange(m_yMin, m_yMax);
}
//===============================================
void GGraphView::drawSample() {
    ui->m_graph->addGraph();
    ui->m_graph->graph()->setLineStyle(QCPGraph::lsImpulse);
    ui->m_graph->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    ui->m_graph->graph()->setPen(QPen(m_color, 1));
    ui->m_graph->graph()->setData(m_xData, m_yData);
    ui->m_graph->xAxis->setRange(m_xMin, m_xMax);
    ui->m_graph->yAxis->setRange(m_yMin, m_yMax);
}
//===============================================
void GGraphView::drawPoint() {
    ui->m_graph->addGraph();
    ui->m_graph->graph()->setLineStyle(QCPGraph::lsNone);
    ui->m_graph->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    ui->m_graph->graph()->setPen(QPen(m_color, 1));
    ui->m_graph->graph()->setData(m_xData, m_yData);
    ui->m_graph->xAxis->setRange(m_xMin, m_xMax);
    ui->m_graph->yAxis->setRange(m_yMin, m_yMax);
}
//===============================================

