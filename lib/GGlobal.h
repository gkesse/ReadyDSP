//===============================================
#ifndef _GGlobal_
#define _GGlobal_
//===============================================
#include <QObject>
//===============================================
class GGlobal : public QObject {
    Q_OBJECT

private:
    GGlobal(QObject* parent = 0);

public:
    ~GGlobal();
    static GGlobal* Instance();

public:
    void swap(double& a, double& b);
    double min(const QVector<double>& data);
    double max(const QVector<double>& data);

private:
    static GGlobal* m_instance;
};

#endif
