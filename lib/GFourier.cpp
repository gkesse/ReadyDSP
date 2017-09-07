//===============================================
#include "GFourier.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
//===============================================
GFourier* GFourier::m_instance = 0;
//===============================================
GFourier::GFourier(QObject *parent) :
    QObject(parent) {

}
//===============================================
GFourier::~GFourier() {

}
//===============================================
GFourier* GFourier::Instance() {
    if(m_instance == 0) {
        m_instance = new GFourier;
    }
    return m_instance;
}
//===============================================
void GFourier::setData(const QVector<double>& data) {
    int N = data.size();
    m_data.fill(0.0, 2*N);

    for(int i = 0; i < N; i++) {
        m_data[2*i] = data[i];
    }
}
//===============================================
QVector<double> GFourier::getXHarm() const {
    return m_xHarm;
}
//===============================================
QVector<double> GFourier::getYHarm() const {
    return m_yHarm;
}
//===============================================
double GFourier::getXmin() const {
    return m_xMin;
}
//===============================================
double GFourier::getXmax() const {
    return m_xMax;
}
//===============================================
double GFourier::getYmin() const {
    return m_yMin;
}
//===============================================
double GFourier::getYmax() const {
    return m_yMax + 0.1*m_yMax;
}
//===============================================
void GFourier::fft(const int &isign) {
    ulong nn = m_data.size()/2;
    ulong n,mmax,m,j,istep,i;
    double wtemp,wr,wpr,wpi,wi,theta;
    float tempr,tempi;
    n=nn << 1;
    j=1;
    for (i=1;i<n;i+=2) {
        if (j > i) {
            SWAP(m_data[j],m_data[i]);
            SWAP(m_data[j+1],m_data[i+1]);
        }
        m=nn;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }

    mmax=2;
    while (n > mmax) {
        istep=mmax << 1;
        theta=isign*(6.28318530717959/mmax);
        wtemp=sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi=sin(theta);
        wr=1.0;
        wi=0.0;
        for (m=1;m<mmax;m+=2) {
            for (i=m;i<=n;i+=istep) {
                j=i+mmax;
                tempr=wr*m_data[j]-wi*m_data[j+1];
                tempi=wr*m_data[j+1]+wi*m_data[j];
                m_data[j]=m_data[i]-tempr;
                m_data[j+1]=m_data[i+1]-tempi;
                m_data[i] += tempr;
                m_data[i+1] += tempi;
            }
            wr=(wtemp=wr)*wpr-wi*wpi+wr;
            wi=wi*wpr+wtemp*wpi+wi;
        }
        mmax=istep;
    }
}
//===============================================
void GFourier::harmonic() {
    int N = m_data.size()/2;
    m_xHarm.resize(N);
    m_yHarm.resize(N);
    m_yMax = 0;

    for(int i = 0; i < N; i++) {
        double ai = m_data[2*i];
        double bi = m_data[2*i + 1];
        double di = qSqrt(ai*ai + bi*bi);
        m_xHarm[i] = i;
        m_yHarm[i] = di;
        if(m_yMax < di) m_yMax = di;
    }

    m_xMin = 0;
    m_xMax = N;
    m_yMin = 0;
}
//===============================================
