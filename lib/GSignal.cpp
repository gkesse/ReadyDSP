//===============================================
#include "GSignal.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GSignal* GSignal::m_instance = 0;
//===============================================
GSignal::GSignal(QObject *parent) :
QObject(parent) {

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
    return m_xmin;
}
//===============================================
double GSignal::getXmax() const {
    return m_xmax;
}
//===============================================
double GSignal::getYmin() const {
    return m_ymin;
}
//===============================================
double GSignal::getYmax() const {
    return m_ymax;
}
//===============================================
void GSignal::square() {
    double F = 50;
    double T = 1/F;
    double tmin = -2*T;
    double tmax = 2*T;
    int N = 10;
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
    m_xmin = tmin;
    m_xmax = tmax;
    m_ymin = Vmin;
    m_ymax = Vmax;
}
//===============================================

