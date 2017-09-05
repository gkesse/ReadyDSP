//===============================================
#include "GSampling.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
//===============================================
GSampling* GSampling::m_instance = 0;
//===============================================
GSampling::GSampling(QObject *parent) :
    QObject(parent) {

}
//===============================================
GSampling::~GSampling() {

}
//===============================================
GSampling* GSampling::Instance() {
    if(m_instance == 0) {
        m_instance = new GSampling;
    }
    return m_instance;
}
//===============================================
void GSampling::setX(const QVector<double>& x) {
    m_xData = x;
}
//===============================================
void GSampling::setY(const QVector<double>& y) {
    m_yData = y;
}
//===============================================
QVector<double> GSampling::getX() const {
    return m_xSamp;
}
//===============================================
QVector<double> GSampling::getY() const {
    return m_ySamp;
}
//===============================================
void GSampling::run() {
    int N = 5;
    int Nmax = (int)qPow(2.0, (double)N);
    int Dmax = m_xData.size();
    int Ne = Dmax/Nmax;
    int j = 0;

    m_xSamp.resize(Nmax);
    m_ySamp.resize(Nmax);

    for(int i = 0; i < Dmax; i++) {
        if((i % Ne) == 0) {
            m_xSamp[j] = m_xData[i];
            m_ySamp[j] = m_yData[i];
            QString m_format = QString("%1 : (%2 ; %3) : (%4 ; %5)")
                    .arg(j).arg(m_xSamp[j]).arg(m_ySamp[j])
                    .arg(m_xData[i]).arg(m_yData[i]);
            GMessageView::Instance()->showData(m_format);
            j++;
        }
    }
}
//===============================================
