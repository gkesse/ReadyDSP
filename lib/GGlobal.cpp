//===============================================
#include "GGlobal.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GGlobal* GGlobal::m_instance = 0;
//===============================================
GGlobal::GGlobal(QObject *parent) :
QObject(parent) {

}
//===============================================
GGlobal::~GGlobal() {

}
//===============================================
GGlobal* GGlobal::Instance() {
    if(m_instance == 0) {
        m_instance = new GGlobal;
    }
    return m_instance;
}
//===============================================
void GGlobal::swap(double &a, double &b) {
    double m_tmp = a;
    a = b;
    b = m_tmp;
}
//===============================================
