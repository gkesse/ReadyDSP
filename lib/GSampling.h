//===============================================
#ifndef _GSampling_
#define _GSampling_
//===============================================
#include <QObject>
#include <QVector>
//===============================================
class GSampling : public QObject {
    Q_OBJECT

private:
    GSampling(QObject* parent = 0);

public:
    ~GSampling();
    static GSampling* Instance();

public:
    void setX(const QVector<double>& x);
    void setY(const QVector<double>& y);
    QVector<double> getX() const;
    QVector<double> getY() const;

public:
    void sample(const int& N = 5);

private:
    static GSampling* m_instance;
    QVector<double> m_xData;
    QVector<double> m_yData;
    QVector<double> m_xSamp;
    QVector<double> m_ySamp;
};

#endif
