//===============================================
#ifndef _GInterPol_
#define _GInterPol_
//===============================================
#include <QObject>
#include <QVector>
//===============================================
class GInterPol : public QObject {
    Q_OBJECT

private:
    GInterPol(QObject* parent = 0);

public:
    ~GInterPol();
    static GInterPol* Instance();

public:
    void setX(const QVector<double>& x);
    void setY(const QVector<double>& y);
    QVector<double> getX() const;
    QVector<double> getY() const;

public:
    void polynomial();
    double polynomial(const double& x);

private:
    static GInterPol* m_instance;
    QVector<double> m_xData;
    QVector<double> m_yData;
    QVector<double> m_xInter;
    QVector<double> m_yInter;
};

#endif
