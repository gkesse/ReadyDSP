//===============================================
#include "GProcess.h"
#include "GSignal.h"
#include "GGraphView.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess(QObject *parent) :
QObject(parent) {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::run() {
    GSignal::Instance()->square();
    GSignal::Instance()->average();
    GSignal::Instance()->variance();
    GSignal::Instance()->stdDeviation();
    GSignal::Instance()->fft();

    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    QVector<double> m_yAvg = GSignal::Instance()->getYAvg();
    QVector<double> m_yStdDev = GSignal::Instance()->getYStdDev();
    QVector<double> m_yFFT = GSignal::Instance()->getYFFT();
    double m_xmin = GSignal::Instance()->getXmin();
    double m_xmax = GSignal::Instance()->getXmax();
    double m_ymin = GSignal::Instance()->getYmin();
    double m_ymax = GSignal::Instance()->getYmax();

    QCustomPlot* m_graph = GGraphView::Instance()->graph();
    m_graph->addGraph();
    m_graph->graph(0)->setData(m_x, m_y);
    m_graph->graph(0)->setPen(QPen(QBrush("blue"), 2));

    m_graph->addGraph();
    m_graph->graph(1)->setData(m_x, m_yAvg);
    m_graph->graph(1)->setPen(QPen(QBrush("green"), 2));

    m_graph->addGraph();
    m_graph->graph(2)->setData(m_x, m_yStdDev);
    m_graph->graph(2)->setPen(QPen(QBrush("red"), 2));

    m_graph->addGraph();
    m_graph->graph(3)->setData(m_x, m_yFFT);
    m_graph->graph(3)->setPen(QPen(QBrush("purple"), 2));

    m_graph->xAxis->setRange(m_xmin, m_xmax);
    m_graph->yAxis->setRange(m_ymin, m_ymax);
}
//===============================================
