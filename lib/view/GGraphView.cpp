//===============================================
#include "GGraphView.h"
#include "ui_GGraphView.h"
//===============================================
GGraphView* GGraphView::m_instance = 0;
//===============================================
GGraphView::GGraphView(QWidget *parent) :
    QWidget(parent), ui(new Ui::GGraphView) {
    ui->setupUi(this);
    int N = 2;
    m_xMin.resize(N);
    m_xMax.resize(N);
    m_yMin.resize(N);
    m_yMax.resize(N);

    for(int i = 0; i < N; i++) {
        m_xMin[i] = 0.0;
        m_xMax[i] = 0.0;
        m_yMin[i] = 0.0;
        m_yMax[i] = 0.0;
    }

    m_graph.push_back(ui->m_graph);
    m_graph.push_back(ui->m_graph2);
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
void GGraphView::setXRange(const double& xMin, const double& xMax, const int &id) {
    if(m_xMin[id] > xMin) m_xMin[id] = xMin;
    if(m_xMax[id] < xMax) m_xMax[id] = xMax;
}
//===============================================
void GGraphView::setYRange(const double& yMin, const double& yMax, const int& id) {
    if(m_yMin[id] > yMin) m_yMin[id] = yMin;
    if(m_yMax[id] < yMax) m_yMax[id] = yMax;
}
//===============================================
void GGraphView::drawGraph(const int& id) {
    m_graph[id]->addGraph();
    m_graph[id]->graph()->setPen(QPen(m_color, 1));
    m_graph[id]->graph()->setData(m_xData, m_yData);
    m_graph[id]->xAxis->setRange(m_xMin[id], m_xMax[id]);
    m_graph[id]->yAxis->setRange(m_yMin[id], m_yMax[id]);
}
//===============================================
void GGraphView::drawSample(const int& id) {
    m_graph[id]->addGraph();
    m_graph[id]->graph()->setLineStyle(QCPGraph::lsImpulse);
    m_graph[id]->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    m_graph[id]->graph()->setPen(QPen(m_color, 1));
    m_graph[id]->graph()->setData(m_xData, m_yData);
    m_graph[id]->xAxis->setRange(m_xMin[id], m_xMax[id]);
    m_graph[id]->yAxis->setRange(m_yMin[id], m_yMax[id]);
}
//===============================================
void GGraphView::drawPoint(const int& id) {
    m_graph[id]->addGraph();
    m_graph[id]->graph()->setLineStyle(QCPGraph::lsNone);
    m_graph[id]->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    m_graph[id]->graph()->setPen(QPen(m_color, 1));
    m_graph[id]->graph()->setData(m_xData, m_yData);
    m_graph[id]->xAxis->setRange(m_xMin[id], m_xMax[id]);
    m_graph[id]->yAxis->setRange(m_yMin[id], m_yMax[id]);
}
//===============================================

