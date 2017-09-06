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
    GSignal::Instance()->polynomial();

    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xMin = GSignal::Instance()->getXmin();
    double m_xMax = GSignal::Instance()->getXmax();
    double m_yMin = GSignal::Instance()->getYmin();
    double m_yMax = GSignal::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();
}
//===============================================
