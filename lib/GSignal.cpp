//===============================================
#include "GSignal.h"
#include "GMessageView.h"
#include "GGlobal.h"
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
QVector<double> GSignal::getYFFT() const {
    return m_yFFT;
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
void GSignal::fft() {
    m_yFFT = m_y;

    /*ulong n;
    ulong mmax;
    ulong m;
    ulong j;
    ulong istep;
    ulong i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    ulong nn = m_yFFT.size() - 1;
    n = nn<<1;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            GGlobal::Instance()->swap(m_yFFT[j-1], m_yFFT[i-1]);
            GGlobal::Instance()->swap(m_yFFT[j], m_yFFT[i]);
        }
        m = nn;
        while (m>=2 && j>m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    };

    // here begins the Danielson-Lanczos section
    mmax=2;
    while (n>mmax) {
        istep = mmax<<1;
        theta = -(2*M_PI/mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m=1; m < mmax; m += 2) {
            for (i=m; i <= n; i += istep) {
                j=i+mmax;
                tempr = wr*m_yFFT[j-1] - wi*m_yFFT[j];
                tempi = wr * m_yFFT[j] + wi*m_yFFT[j-1];

                m_yFFT[j-1] = m_yFFT[i-1] - tempr;
                m_yFFT[j] = m_yFFT[i] - tempi;
                m_yFFT[i-1] += tempr;
                m_yFFT[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }*/
}
//===============================================
