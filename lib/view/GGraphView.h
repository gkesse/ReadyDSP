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
    QCustomPlot* graph() const;

private:
    static GGraphView* m_instance;
    Ui::GGraphView *ui;
};
//===============================================
#endif
//===============================================
