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
QVector<double> GSignal::getYAvg() const {
    return m_yAvg;
}
//===============================================
QVector<double> GSignal::getYVar() const {
    return m_yVar;
}
//===============================================
QVector<double> GSignal::getYStdDev() const {
    return m_yStdDev;
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
double GSignal::getAvg() const {
    return m_avg;
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
void GSignal::average() {
    double Sum = 0;
    double N = m_y.size();
    m_yAvg.resize(N);

    for(int i = 0; i < N; i++) {
        double Yi = m_y[i];
        Sum += Yi;
    }

    m_avg = Sum/N;

    for(int i = 0; i < N; i++) {
        m_yAvg[i] = m_avg;
    }
}
//===============================================
void GSignal::variance() {
    double Sum = 0;
    double Sum2 = 0;
    double N = m_y.size();
    m_yVar.resize(N);

    for(int i = 0; i < N; i++) {
        double Yi = m_y[i];
        Sum += Yi;
        Sum2 += Yi*Yi;
    }

    m_avg = Sum/N;
    m_var = Sum2/N - m_avg*m_avg;

    for(int i = 0; i < N; i++) {
        m_yVar[i] = m_var;
    }
}
//===============================================
void GSignal::stdDeviation() {
    double Sum = 0;
    double Sum2 = 0;
    double N = m_y.size();
    m_yStdDev.resize(N);

    for(int i = 0; i < N; i++) {
        double Yi = m_y[i];
        Sum += Yi;
        Sum2 += Yi*Yi;
    }

    m_avg = Sum/N;
    m_var = Sum2/N - m_avg*m_avg;
    m_stdDev = qSqrt(m_var);

    for(int i = 0; i < N; i++) {
        m_yStdDev[i] = m_stdDev;
    }
}
//===============================================

