//===============================================
#include "GProcess.h"
#include "GSignal.h"
#include "GSampling.h"
#include "GInterPol.h"
#include "GIntegrate.h"
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
    GSignal::Instance()->sinus();
    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xMin = GSignal::Instance()->getXmin();
    double m_xMax = GSignal::Instance()->getXmax();
    double m_yMin = GSignal::Instance()->getYmin();
    double m_yMax = GSignal::Instance()->getYmax();

    GIntegrate::Instance()->setX(m_x);
    GIntegrate::Instance()->setY(m_y);
    GIntegrate::Instance()->gaussLegendre();
    QVector<double> m_xInteg = GIntegrate::Instance()->getX();
    QVector<double> m_yInteg = GIntegrate::Instance()->getY();
    double m_xMin2 = GIntegrate::Instance()->getXmin();
    double m_xMax2 = GIntegrate::Instance()->getXmax();
    double m_yMin2 = GIntegrate::Instance()->getYmin();
    double m_yMax2 = GIntegrate::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xInteg, m_yInteg);
    GGraphView::Instance()->setXRange(m_xMin2, m_xMax2, 1);
    GGraphView::Instance()->setYRange(m_yMin2, m_yMax2, 1);
    GGraphView::Instance()->drawGraph(1);
}
//===============================================
