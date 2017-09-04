//===============================================
#include "GMinMax.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GMinMax* GMinMax::m_instance = 0;
//===============================================
GMinMax::GMinMax(QObject *parent) :
    QObject(parent) {

}
//===============================================
GMinMax::~GMinMax() {

}
//===============================================
GMinMax* GMinMax::Instance() {
    if(m_instance == 0) {
        m_instance = new GMinMax;
    }
    return m_instance;
}
//===============================================
void GMinMax::setData(const QVector<double>& data) {
    m_data = data;
}
//===============================================
double GMinMax::getMin() const {
    return m_min;
}
//===============================================
double GMinMax::getMax() const {
    return m_max;
}
//===============================================
void GMinMax::run() {
    m_min = m_data[0];
    m_max = m_data[0];

    for(int i = 0; i < m_data.size(); i++) {
        double di = m_data[i];
        if(m_min > di) m_min = di;
        if(m_max < di) m_max = di;
    }
}
//===============================================
