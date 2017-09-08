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
    void integrate();
    void gaussLegendre();

private:
    static GIntegrate* m_instance;
    QVector<double> m_xData;
    QVector<double> m_yData;
    QVector<double> m_xParam;
    QVector<double> m_wParam;
    QVector<double> m_Coef;
};

#endif
