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
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
    double m_xWidth;
    double m_yWidth;
    double m_border;
};

#endif
