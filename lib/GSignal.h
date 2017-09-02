//===============================================
#ifndef _GSignal_
#define _GSignal_
//===============================================
#include <QObject>
#include <QVector>
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
    QVector<double> getYAvg() const;
    QVector<double> getYVar() const;
    QVector<double> getYStdDev() const;
    QVector<double> getYFFT() const;
    double getXmin() const;
    double getXmax() const;
    double getYmin() const;
    double getYmax() const;
    double getAvg() const;

public:
    void square();
    void average();
    void variance();
    void stdDeviation();
    void fft();

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
    double m_border;

    QVector<double> m_yAvg;
    double m_avg;

    QVector<double> m_yVar;
    double m_var;

    QVector<double> m_yStdDev;
    double m_stdDev;

    QVector<double> m_yFFT;
};

#endif
