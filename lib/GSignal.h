//===============================================
#ifndef _GSignal_
#define _GSignal_
//===============================================
#include <QObject>
//===============================================
class GSignal : public QObject {
    Q_OBJECT

private:
    GSignal(QObject* parent = 0);

public:
    ~GSignal();
    static GSignal* Instance();

public:
    void square();
    
private:
    static GSignal* m_instance;
};

#endif
