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
    void setXRange(const double& xMin, const double& xMax, const int& id = 0);
    void setYRange(const double& yMin, const double& yMax, const int& id = 0);

public:
    void drawGraph(const int& id = 0);
    void drawSample(const int& id = 0);
    void drawPoint(const int& id = 0);

private:
    static GGraphView* m_instance;
    Ui::GGraphView *ui;
    QBrush m_color;
    QVector<double> m_xData;
    QVector<double> m_yData;
    QVector<QCustomPlot*> m_graph;
    QVector<double> m_xMin;
    QVector<double> m_xMax;
    QVector<double> m_yMin;
    QVector<double> m_yMax;
};
//===============================================
#endif
//===============================================
