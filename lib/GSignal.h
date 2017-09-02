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
    double getXmin() const;
    double getXmax() const;
    double getYmin() const;
    double getYmax() const;

public:
    void square();
    
private:
    static GSignal* m_instance;
    QVector<double> m_x;
    QVector<double> m_y;
    double m_xmin;
    double m_xmax;
    double m_ymin;
    double m_ymax;
};

#endif
