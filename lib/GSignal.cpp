//===============================================
#include "GSignal.h"
#include "GMinMax.h"
#include "GMessageView.h"
#include <QtMath>
//===============================================
GSignal* GSignal::m_instance = 0;
//===============================================
GSignal::GSignal(QObject *parent) :
    QObject(parent) {
    m_yBorder = 0.1;
    Npow = 8;
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
QVector<double> GSignal::getX() const {
    return m_x;
}
//===============================================
QVector<double> GSignal::getY() const {
    return m_y;
}
//===============================================
double GSignal::getXmin() const {
    return m_xMin;
}
//===============================================
double GSignal::getXmax() const {
    return m_xMax;
}
//===============================================
double GSignal::getYmin() const {
    return m_yMin - m_yBorder*m_yWidth;
}
//===============================================
double GSignal::getYmax() const {
    return m_yMax + m_yBorder*m_yWidth;
}
//===============================================
void GSignal::sinus() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_paramMap.insert("ID", "sinus");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmax", Vmax);

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = sinus(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::cosinus() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_paramMap.insert("ID", "cosinus");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmax", Vmax);

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = cosinus(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::halfwave() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_paramMap.insert("ID", "halfwave");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmax", Vmax);
    m_paramMap.insert("tmin", tmin);
    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = halfwave(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::fullwave() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = +1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmax = 2;

    m_paramMap.insert("ID", "fullwave");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmax", Vmax);
    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = fullwave(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = -Vmax;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::square() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = 1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = +1;

    m_paramMap.insert("ID", "square");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmin", Vmin);
    m_paramMap.insert("Vmax", Vmax);
    m_paramMap.insert("tmin", tmin);

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = square(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::triangle() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = 1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = +1;

    m_paramMap.insert("ID", "triangle");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmin", Vmin);
    m_paramMap.insert("Vmax", Vmax);
    m_paramMap.insert("tmin", tmin);

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = triangle(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::sawtooth() {
    double F = 50;
    double T = 1/F;
    double tmin = -1*T;
    double tmax = 1*T;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);
    double Vmin = -1;
    double Vmax = +1;

    m_paramMap.insert("ID", "sawtooth");
    m_paramMap.insert("F", F);
    m_paramMap.insert("Vmin", Vmin);
    m_paramMap.insert("Vmax", Vmax);
    m_paramMap.insert("tmin", tmin);

    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = sawtooth(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = Vmin;
    m_yMax = Vmax;
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
void GSignal::polynomial() {
    double A[] = {1.0/4, 3.0/4, -3.0/2, -2.0};
    int N = sizeof(A)/sizeof(double);
    double tmin = -5;
    double tmax = 3;
    int Nmax = (int)qPow(2.0, (double)Npow);
    double Te = (tmax - tmin)/(Nmax - 1);

    QString Coef = "";
    for(int i = 0; i < N; i++) {
        if(i != 0) Coef += ";";
        Coef += QString("%1").arg(A[i]);
    }

    m_paramMap.insert("ID", "polynomial");
    m_paramMap.insert("Coef", Coef);
    m_x.resize(Nmax);
    m_y.resize(Nmax);

    for(int i = 0; i < Nmax; i++) {
        double xi = tmin + i*Te;
        double yi = polynomial(xi);
        m_x[i] = xi;
        m_y[i] = yi;
    }

    GMinMax::Instance()->setData(m_y);
    GMinMax::Instance()->minMax();
    m_xMin = tmin;
    m_xMax = tmax;
    m_yMin = GMinMax::Instance()->getMin();
    m_yMax = GMinMax::Instance()->getMax();
    m_xWidth = m_xMax - m_xMin;
    m_yWidth = m_yMax - m_yMin;
}
//===============================================
double GSignal::signal(const double& x) {
    QString id = m_paramMap.value("ID").toString();
    double y;
    if(id == "sinus") y = sinus(x);
    else if(id == "cosinus") y = cosinus(x);
    else if(id == "halfwave") y = halfwave(x);
    else if(id == "fullwave") y = fullwave(x);
    else if(id == "square") y = square(x);
    else if(id == "triangle") y = triangle(x);
    else if(id == "sawtooth") y = sawtooth(x);
    else if(id == "polynomial") y = polynomial(x);
    return y;
}
//===============================================
double GSignal::sinus(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();

    double W = 2*M_PI*F;
    double y = Vmax*qSin(W*x);
    return y;
}
//===============================================
double GSignal::cosinus(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();

    double W = 2*M_PI*F;
    double y = Vmax*qCos(W*x);
    return y;
}
//===============================================
double GSignal::halfwave(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();
    double x0 = m_paramMap.value("tmin").toDouble();

    double W = 2*M_PI*F;
    double T = 1/F;
    double dx = x - x0;
    int xA = dx/T;
    double xB = dx - xA*T;
    double xT = T/2;
    double y;
    if(xB < xT) y = Vmax*qSin(W*dx);
    else y = 0;
    return y;
}
//===============================================
double GSignal::fullwave(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();

    double W = 2*M_PI*F;
    double y = qAbs(Vmax*qSin(W*x));
    return y;
}
//===============================================
double GSignal::square(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmin = m_paramMap.value("Vmin").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();
    double x0 = m_paramMap.value("tmin").toDouble();

    double T = 1/F;
    double dx = x - x0;
    int xA = dx/T;
    double xB = dx - xA*T;
    double xT = T/2;
    double y;
    if(xB < xT) y = Vmax;
    else y = Vmin;
    return y;
}
//===============================================
double GSignal::triangle(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmin = m_paramMap.value("Vmin").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();
    double x0 = m_paramMap.value("tmin").toDouble();

    double T = 1/F;
    double dx = x - x0;
    int xA = dx/T;
    double xB = dx - xA*T;
    double xT = T/2;
    double A = 2*(Vmax - Vmin)/T;
    double y;
    if(xB < xT) y = A*xB + Vmin;
    else y = -A*(xB - xT) + Vmax;
    return y;
}
//===============================================
double GSignal::sawtooth(const double& x) {
    double F = m_paramMap.value("F").toDouble();
    double Vmin = m_paramMap.value("Vmin").toDouble();
    double Vmax = m_paramMap.value("Vmax").toDouble();
    double x0 = m_paramMap.value("tmin").toDouble();

    double T = 1/F;
    double dx = x - x0;
    int xA = dx/T;
    double xB = dx - xA*T;
    double A = (Vmax - Vmin)/T;
    double y = A*xB + Vmin;
    return y;
}
//===============================================
double GSignal::polynomial(const double& x) {
    QString Coef = m_paramMap.value("Coef").toString();
    QStringList CoefA = Coef.split(";");
    int N = CoefA.size();
    int D = N - 1;
    QVector<double> A(N);
    for(int i = 0; i < N; i++) A[i] = ((QString)CoefA.at(i)).toDouble();
    double y = 0.0;

    for(int i = 0; i <= D; i++) {
        double ai = A[i];
        if(ai == 0) continue;
        double xi = qPow(x, (double)(D - i));
        double yi = ai*xi;
        y += yi;
    }

    return y;
}
//===============================================
