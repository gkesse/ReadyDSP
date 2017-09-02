//===============================================
#include "GSignal.h"
//===============================================
GSignal* GSignal::m_instance = 0;
//===============================================
GSignal::GSignal(QObject *parent) :
QObject(parent) {

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
void GSignal::square() {
    double F = 50;
    double T = 1/F;
    double w = 2*1;
}
//===============================================

