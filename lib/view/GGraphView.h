//===============================================
#ifndef _GGraphView_
#define _GGraphView_
//===============================================
#include <QWidget>
#include "qcustomplot.h"
//===============================================
namespace Ui {
class GGraphView;
}
//===============================================
class GGraphView : public QWidget {
    Q_OBJECT

private:
    GGraphView(QWidget *parent = 0);

public:
    ~GGraphView();
    static GGraphView* Instance();

protected:
    void closeEvent(QCloseEvent *event);

public:
    void setColor(const QBrush& color);
    void setData(const QVector<double>& x, const QVector<double>& y);
    void setXRange(const double& xMin, const double& xMax);
    void setYRange(const double& yMin, const double& yMax);

public:
    void drawGraph();
    void drawSample();

private:
    static GGraphView* m_instance;
    Ui::GGraphView *ui;
    QBrush m_color;
    QVector<double> m_xData;
    QVector<double> m_yData;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
    int m_id;
};
//===============================================
#endif
//===============================================
