//===============================================
#include "GSignal.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GSignal* GSignal::m_instance = 0;
//===============================================
GSignal::GSignal(QObject *parent) :
QObject(parent) {
    m_border = 0.1;
}
//===============================================
GSignal::~GSignal() {

}
//===============================================
GSignal* GSignal::Instance() {
    if(m_instance == 0) {
        m_instance = new GSignal;
    }
    return m_instance;
}
//===============================================
QVector<double> GSignal::getX() const {
    return m_x;
}
//===============================================
QVector<double> GSignal::getY() const {
    return m_y;
}
//===============================================
double GSignal::getXmin() const {
    return m_xMin;
}
//===============================================
double GSignal::getXmax() const {
    return m_xMax;
}
//===============================================
double GSignal::getYmin() const {
    return m_yMin - m_border*m_yWidth;
}
//===============================================
double GSignal::getYmax() const {
    return m_yMax + m_border*m_yWidth;
}
//===============================================
void GSignal::square() {
    double F = 50;
    double T = 1/F;
    double tmin = -2*T;
    double tmax = 2*T;
    int N = 100;
    double Te = T/N;
    int Nmax = (tmax - tmin)/Te;
    double Vmin = -1;
    double Vmax = 1;

    m_x.resize(Nmax + 1);
    m_y.resize(Nmax + 1);

    for(int i = 0; i <= Nmax; i++) {
        double dt = i*Te;
        double xt = tmin + dt;
        double yt;
        if((i % N) <= (N/2)) yt = Vmax;
        else yt = Vmin;
        m_x[i] = xt;
        m_y[i] = yt;
    }
    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================

