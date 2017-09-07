//===============================================
#include "GInterPol.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GInterPol* GInterPol::m_instance = 0;
//===============================================
GInterPol::GInterPol(QObject *parent) :
    QObject(parent) {

}
//===============================================
GInterPol::~GInterPol() {

}
//===============================================
GInterPol* GInterPol::Instance() {
    if(m_instance == 0) {
        m_instance = new GInterPol;
    }
    return m_instance;
}
//===============================================
void GInterPol::setX(const QVector<double>& x) {
    m_xData = x;
}
//===============================================
void GInterPol::setY(const QVector<double>& y) {
    m_yData = y;
}
//===============================================
QVector<double> GInterPol::getX() const {
    return m_xInter;
}
//===============================================
QVector<double> GInterPol::getY() const {
    return m_yInter;
}
//===============================================
void GInterPol::compute() {
    double tmin = m_xData.first();
    double tmax = m_xData.last();
    int Npow = 8;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    m_xInter.resize(Nmax);
    m_yInter.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = compute(xi);
        m_xInter[i] = xi;
        m_yInter[i] = yi;
    }
}
//===============================================
double GInterPol::compute(const double& x) {
    int N = m_Coef.size();
    double y = 0.0;

    for(int i = 0; i < N; i++) {
        double ci = m_Coef[i];
        if(ci == 0) continue;
        double xi = qPow(x, (double)i);
        double yi = ci*xi;
        y += yi;
    }

    return y;
}
//===============================================
void GInterPol::polynomial() {
    int k,j,i;
    double phi,ff,b;
    int n = m_xData.size();
    QVector<double> s(n);
    m_Coef.resize(n);

    for (i=0;i<=n-1;i++) s[i]=m_Coef[i]=0.0;
    s[n-1] = -m_xData[0];
    for (i=1;i<=n-1;i++) {
        for (j=n-1-i;j<=n-1-1;j++)
            s[j] -= m_xData[i]*s[j+1];
        s[n-1] -= m_xData[i];
    }
    for (j=0;j<=n-1;j++) {
        phi=n-1+1;
        for (k=n-1;k>=1;k--)
            phi=k*s[k]+m_xData[j]*phi;
        ff=m_yData[j]/phi;
        b=1.0;

        for (k=n-1;k>=0;k--) {
            m_Coef[k] += b*ff;
            b=s[k]+m_xData[j]*b;
        }
    }
}
//===============================================
