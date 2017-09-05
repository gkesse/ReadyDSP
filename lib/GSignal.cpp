//===============================================
#include "GSignal.h"
#include "GMinMax.h"
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
void GSignal::sinus() {
    double F = 50;
    double W = 2*M_PI*F;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi = Vmax*qSin(W*xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::cosinus() {
    double F = 50;
    double W = 2*M_PI*F;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi = Vmax*qCos(W*xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::halfwave() {
    double F = 50;
    double W = 2*M_PI*F;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi;
        if((i % N) < (N/2)) yi = Vmax*qSin(W*xi);
        else yi = 0;
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::fullwave() {
    double F = 50;
    double W = 2*M_PI*F;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi;
        if((i % N) < (N/2)) yi = Vmax*qSin(W*xi);
        else yi = -Vmax*qSin(W*xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::square() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = 1;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi;
        if((i % N) < (N/2)) yi = Vmax;
        else yi = Vmin;
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::triangle() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = 1;
    double A = 2*(Vmax - Vmin)/T;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi;
        double x0;
        if((i % N) == 0) x0 = xi;
        if((i % N) == (N/2)) x0 = xi;
        if((i % N) < (N/2)) yi = A*(xi - x0) + Vmin;
        else yi = -A*(xi - x0) + Vmax;
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::sawtooth() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = 1;
    double A = (Vmax - Vmin)/T;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi;
        double x0;
        if((i % N) == 0) x0 = xi;
        yi = A*(xi - x0) + Vmin;
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::polynomial() {
    double A[] = {1.0/4, 3.0/4, -3.0/2, -2.0};
    int S = sizeof(A)/sizeof(double);
    int D = S - 1;
    double tmin = -5;
    double tmax = 3;
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double di = i*Te;
        double xi = tmin + di;
        double yi = 0;

        for(int j = 0; j <= D; j++) {
            double aj = A[j];
            if(aj == 0) continue;
            double xj = qPow(xi, (double)(D - j));
            double yj = aj*xj;
            yi += yj;
        }
        m_x[i] = xi;
        m_y[i] = yi;
    }

    GMinMax::Instance()->setData(m_y);
    GMinMax::Instance()->run();
    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = GMinMax::Instance()->getMin();
    m_yMax = GMinMax::Instance()->getMax();
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
