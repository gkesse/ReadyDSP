//===============================================
#ifndef _GMessageView_
#define _GMessageView_
//===============================================
#include <QWidget>
//===============================================
namespace Ui {
class GMessageView;
}
//===============================================
class GMessageView : public QWidget {
    Q_OBJECT

private:
    GMessageView(QWidget *parent = 0);

public:
    ~GMessageView();
    static GMessageView* Instance();

private:
    void setPosition();

public:
    void showData(const QString& data, const QString& name = "");

private:
    static GMessageView* m_instance;
    Ui::GMessageView *ui;
};
//===============================================
#endif
//===============================================
