//===============================================
#include "GInterPol.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
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
void GInterPol::polynomial() {
    double tmin = m_xData.first();
    double tmax = m_xData.last();
    int Npow = 5;
    int Nmax = (int)qPow(2.0, (double)Npow) + 1;
    double Te = (tmax - tmin)/(Nmax - 1);
    m_xInter.resize(Nmax);
    m_yInter.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = polynomial(xi);
        m_xInter[i] = xi;
        m_yInter[i] = yi;
        QString m_format = QString("%1 : %2 : %3")
                .arg(i).arg(xi).arg(yi);
        GMessageView::Instance()->showData(m_format);
    }
}
//===============================================
double GInterPol::polynomial(const double& x) {
    int i,m,ns=1;
    double den,dif,dift,ho,hp,w;
    double y;
    double dy;
    int n = m_xData.size();
    QVector<double> c(n),d(n);

    dif=fabs(x - m_xData[1]);
    for (i=1;i<=n;i++) {
        if ( (dift=fabs(x-m_xData[i])) < dif) {
            ns=i;
            dif=dift;
        }
        c[i]=m_yData[i];
        d[i]=m_yData[i];
    }
    y=m_yData[ns--];
    for (m=1;m<n;m++) {
        for (i=1;i<=n-m;i++) {
            ho=m_xData[i]-x;
            hp=m_xData[i+m]-x;
            w=c[i+1]-d[i];
            if ( (den=ho-hp) == 0.0) return NAN;
            den=w/den;
            d[i]=hp*den;
            c[i]=ho*den;
        }
        y += (dy=(2*ns < (n-m) ? c[ns+1] : d[ns--]));
    }
    return y;
}
//===============================================
