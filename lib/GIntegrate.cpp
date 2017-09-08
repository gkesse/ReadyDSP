//===============================================
#include "GIntegrate.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
#define EPS 3.0e-11
//===============================================
GIntegrate* GIntegrate::m_instance = 0;
//===============================================
GIntegrate::GIntegrate(QObject *parent) :
    QObject(parent) {

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
    return m_xParam;
}
//===============================================
QVector<double> GIntegrate::getY() const {
    return m_wParam;
}
//===============================================
void GIntegrate::integrate() {
    int m,j,i;
    double z1,z,xm,xl,pp,p3,p2,p1;
    int n = 3;
    double x1 = -1;//m_xData[0];
    double x2 = 1;//m_xData[4];

    m_xParam.resize(n);
    m_wParam.resize(n);

    m=(n+1)/2;
    xm=0.5*(x2+x1);
    xl=0.5*(x2-x1);
    for (i=0;i<=m;i++) {
        z=cos(3.141592654*(i-0.25)/(n+0.5));

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
        m_xParam[n+1-i]=xm+xl*z;
        m_wParam[i]=2.0*xl/((1.0-z*z)*pp*pp);
        m_wParam[n+1-i]=m_wParam[i];
    }
}
//===============================================
void GIntegrate::gaussLegendre() {
    QString m_format = "";
    m_format += "abscissas and weights of the Gauss-Legendre\n";
    m_format += "====================================\n";
    for(int i = 0; i < m_xParam.size(); i++) {
        m_format += QString("x[%1] : %2 --- w[%1] : %3\n")
                .arg(i).arg(m_xParam[i]).arg(m_wParam[i]);
    }
    m_format += "====================================\n";
    GMessageView::Instance()->showData(m_format);
}
//===============================================
