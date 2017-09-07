//===============================================
#include "GProcess.h"
#include "GSignal.h"
#include "GSampling.h"
#include "GInterPol.h"
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

    GSampling::Instance()->setX(m_x);
    GSampling::Instance()->setY(m_y);
    GSampling::Instance()->sample(3);
    QVector<double> m_xSamp = GSampling::Instance()->getX();
    QVector<double> m_ySamp = GSampling::Instance()->getY();

    GInterPol::Instance()->setX(m_xSamp);
    GInterPol::Instance()->setY(m_ySamp);
    GInterPol::Instance()->polynomial();
    GInterPol::Instance()->compute();
    GInterPol::Instance()->coefficient();
    QVector<double> m_xInter = GInterPol::Instance()->getX();
    QVector<double> m_yInter = GInterPol::Instance()->getY();

    GGraphView::Instance()->setColor(QBrush("green"));
    GGraphView::Instance()->setData(m_xInter, m_yInter);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xSamp, m_ySamp);
    GGraphView::Instance()->drawPoint();
}
//===============================================
