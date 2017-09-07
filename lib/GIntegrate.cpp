//===============================================
#include "GIntegrate.h"
#include "GMessageView.h"
#include <QtMath>
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
    return m_xInter;
}
//===============================================
QVector<double> GIntegrate::getY() const {
    return m_yInter;
}
//===============================================
void GIntegrate::integrate() {

}
//===============================================
