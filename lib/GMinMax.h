//===============================================
#ifndef _GMinMax_
#define _GMinMax_
//===============================================
#include <QObject>
#include <QVector>
//===============================================
class GMinMax : public QObject {
    Q_OBJECT

private:
    GMinMax(QObject* parent = 0);

public:
    ~GMinMax();
    static GMinMax* Instance();

public:
    void setData(const QVector<double>& data);
    double getMin() const;
    double getMax() const;

public:
    void run();

private:
    static GMinMax* m_instance;
    QVector<double> m_data;
    double m_min;
    double m_max;
};

#endif
