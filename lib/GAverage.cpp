//===============================================
#include "GAverage.h"
#include "GMessageView.h"
#include "GGlobal.h"
#include <QtMath>
//===============================================
GAverage* GAverage::m_instance = 0;
//===============================================
GAverage::GAverage(QObject *parent) :
    QObject(parent) {
    m_border = 0.1;
}
//===============================================
GAverage::~GAverage() {

}
//===============================================
GAverage* GAverage::Instance() {
    if(m_instance == 0) {
        m_instance = new GAverage;
    }
    return m_instance;
}
//===============================================
QVector<double> GAverage::getX() const {
    return m_x;
}
//===============================================
QVector<double> GAverage::getY() const {
    return m_y;
}
//===============================================
QVector<double> GAverage::getYAvg() const {
    return m_yAvg;
}
//===============================================
QVector<double> GAverage::getYVar() const {
    return m_yVar;
}
//===============================================
QVector<double> GAverage::getYStdDev() const {
    return m_yStdDev;
}
//===============================================
QVector<double> GAverage::getYFFT() const {
    return m_yFFT;
}
//===============================================
double GAverage::getXmin() const {
    return m_xMin;
}
//===============================================
double GAverage::getXmax() const {
    return m_xMax;
}
//===============================================
double GAverage::getYmin() const {
    return m_yMin - m_border*m_yWidth;
}
//===============================================
double GAverage::getYmax() const {
    return m_yMax + m_border*m_yWidth;
}
//===============================================
double GAverage::getAvg() const {
    return m_avg;
}
//===============================================
void GAverage::square() {
    double F = 50;
    double T = 1/F;
    double tmin = -2*T;
    double tmax = 2*T;
    int Npow = 10;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = 1;
    int N = T/Te + 1;

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
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
void GAverage::average() {
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
void GAverage::variance() {
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
void GAverage::stdDeviation() {
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
void GAverage::fft() {
    m_yFFT = m_y;
    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;
    ulong nn = m_yFFT.size()/2;
    // reverse-binary reindexing
    n = nn<<1;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            qSwap(m_yFFT[j-1], m_yFFT[i-1]);
            qSwap(m_yFFT[j], m_yFFT[i]);
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
    }
}
//===============================================
