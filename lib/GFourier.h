//===============================================
#ifndef _GFourier_
#define _GFourier_
//===============================================
#include <QObject>
#include <QVector>
//===============================================
class GFourier : public QObject {
    Q_OBJECT

private:
    GFourier(QObject* parent = 0);

public:
    ~GFourier();
    static GFourier* Instance();

public:
    void setData(const QVector<double>& data);
    QVector<double> getXHarm() const;
    QVector<double> getYHarm() const;
    double getXmin() const;
    double getXmax() const;
    double getYmin() const;
    double getYmax() const;

public:
    void dft(const int& isign = 1);
    void harmonic();

private:
    static GFourier* m_instance;
    QVector<double> m_data;
    QVector<double> m_xHarm;
    QVector<double> m_yHarm;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
};

#endif
