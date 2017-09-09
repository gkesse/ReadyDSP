//===============================================
#ifndef _GIntegrate_
#define _GIntegrate_
//===============================================
#include <QObject>
#include <QVector>
//===============================================
class GIntegrate : public QObject {
    Q_OBJECT

private:
    GIntegrate(QObject* parent = 0);

public:
    ~GIntegrate();
    static GIntegrate* Instance();

public:
    void setX(const QVector<double>& x);
    void setY(const QVector<double>& y);
    QVector<double> getX() const;
    QVector<double> getY() const;

public:
    void gaussLegendre();
    void gaussLegendre(const double &x1, const double &x2, const int &n);
    void params();

private:
    static GIntegrate* m_instance;
    QVector<double> m_xData;
    QVector<double> m_yData;
    QVector<double> m_xParam;
    QVector<double> m_wParam;
    QVector<double> m_xInteg;
    QVector<double> m_yInteg;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
};

#endif
