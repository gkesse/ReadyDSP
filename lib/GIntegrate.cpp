//===============================================
#include "GIntegrate.h"
#include "GSignal.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
#define EPS 3.0e-11
//===============================================
GIntegrate* GIntegrate::m_instance = 0;
//===============================================
GIntegrate::GIntegrate(QObject *parent) :
    QObject(parent) {
    m_yBorder = 0.1;
}
//===============================================
GIntegrate::~GIntegrate() {

}
//===============================================
GIntegrate* GIntegrate::Instance() {
    if(m_instance == 0) {
        m_instance = new GIntegrate;
    }
    return m_instance;
}
//===============================================
void GIntegrate::setX(const QVector<double>& x) {
    m_xData = x;
}
//===============================================
void GIntegrate::setY(const QVector<double>& y) {
    m_yData = y;
}
//===============================================
QVector<double> GIntegrate::getX() const {
    return m_xInteg;
}
//===============================================
QVector<double> GIntegrate::getY() const {
    return m_yInteg;
}
//===============================================
double GIntegrate::getXmin() const {
    return m_xMin;
}
//===============================================
double GIntegrate::getXmax() const {
    return m_xMax;
}
//===============================================
double GIntegrate::getYmin() const {
    return m_yMin - m_yBorder*m_yWidth;
}
//===============================================
double GIntegrate::getYmax() const {
    return m_yMax + m_yBorder*m_yWidth;
}
//===============================================
void GIntegrate::gaussLegendre() {
    int N = m_xData.size();
    double x0 = m_xData[0];

    m_xInteg.resize(N - 1);
    m_yInteg.resize(N - 1);
    m_yMin = 0.0;
    m_yMax = 0.0;

    for(int i = 0; i < N - 1; i++) {
        double xi = m_xData[i];
        gaussLegendre(x0, xi, i + 1);

        double yi = 0.0;

        for(int j = 0; j < i + 1; j++) {
            double xj = m_xParam[j];
            double wj = m_wParam[j];
            double fj = GSignal::Instance()->signal(xj);
            double yj = wj*fj;
            yi += yj;
        }

        if(m_yMin > yi) m_yMin = yi;
        if(m_yMax < yi) m_yMax = yi;

        m_xInteg[i] = xi;
        m_yInteg[i] = yi;
    }

    m_xMin = m_xInteg.first();
    m_xMax = m_xInteg.last();
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GIntegrate::gaussLegendre(const double& x1, const double& x2, const int& n) {
    int m,j,i;
    double z1,z,xm,xl,pp,p3,p2,p1;

    m_xParam.clear();
    m_wParam.clear();

    m_xParam.resize(n);
    m_wParam.resize(n);

    m=(n+1)/2;
    xm=0.5*(x2+x1);
    xl=0.5*(x2-x1);
    for (i=0;i<=m-1;i++) {
        z=cos(3.141592654*((i+1)-0.25)/(n+0.5));

        do {
            p1=1.0;
            p2=0.0;
            for (j=1;j<=n;j++) {
                p3=p2;
                p2=p1;
                p1=((2.0*j-1.0)*z*p2-(j-1.0)*p3)/j;
            }
            pp=n*(z*p1-p2)/(z*z-1.0);
            z1=z;
            z=z1-p1/pp;
        } while (fabs(z-z1) > EPS);

        m_xParam[i]=xm-xl*z;
        m_xParam[n-1-i]=xm+xl*z;
        m_wParam[i]=2.0*xl/((1.0-z*z)*pp*pp);
        m_wParam[n-1-i]=m_wParam[i];
    }
}
//===============================================
void GIntegrate::params() {
    QString m_format = "";
    m_format += "abscissas and weights of the Gauss-Legendre\n";
    m_format += "====================================\n";
    m_format += QString("n : %1\n").arg(m_xParam.size());
    m_format += "====================================\n";
    for(int i = 0; i < m_xParam.size(); i++) {
        m_format += QString("x[%1] : %2 |===| w[%1] : %3\n")
                .arg(i).arg(m_xParam[i]).arg(m_wParam[i]);
    }
    m_format += "====================================\n";
    GMessageView::Instance()->showData(m_format);
}
//===============================================
