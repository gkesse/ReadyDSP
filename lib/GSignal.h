//===============================================
#ifndef _GSignal_
#define _GSignal_
//===============================================
#include <QObject>
#include <QVector>
#include <QMap>
#include <QVariant>
//===============================================
class GSignal : public QObject {
    Q_OBJECT

private:
    GSignal(QObject* parent = 0);

public:
    ~GSignal();
    static GSignal* Instance();

public:
    QVector<double> getX() const;
    QVector<double> getY() const;
    double getXmin() const;
    double getXmax() const;
    double getYmin() const;
    double getYmax() const;

public:
    void sinus();
    void cosinus();
    void halfwave();
    void fullwave();
    void square();
    void triangle();
    void sawtooth();
    void polynomial();

public:
    double signal(const double& x);
    double sinus(const double& x);
    double cosinus(const double& x);
    double square(const double& x);

private:
    static GSignal* m_instance;
    QVector<double> m_x;
    QVector<double> m_y;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
    double m_xWidth;
    double m_yWidth;
    double m_yBorder;
    QMap<QString, QVariant> m_paramMap;
    int Npow;
};

#endif
