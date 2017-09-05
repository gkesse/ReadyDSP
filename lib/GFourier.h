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

public:
    void dft(const int& isign = 1);
    void harmonic();

private:
    static GFourier* m_instance;
    QVector<double> m_data;
    QVector<double> m_harm;
};

#endif
