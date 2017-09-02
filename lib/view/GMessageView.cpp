//===============================================
#include "GMessageView.h"
#include "ui_GMessageView.h"
//===============================================
GMessageView* GMessageView::m_instance = 0;
//===============================================
GMessageView::GMessageView(QWidget *parent) :
QWidget(parent), ui(new Ui::GMessageView) {
    ui->setupUi(this);
    show();
}
//===============================================
GMessageView::~GMessageView() {
    delete ui;
}
//===============================================
GMessageView* GMessageView::Instance() {
    if(m_instance == 0) {
        m_instance = new GMessageView;
    }
    return m_instance;
}
//===============================================
void GMessageView::showData(const QString& data, const QString& name) {
    QString m_format = "";
    if(name != "") m_format += name + " : ";
    m_format += data;
    ui->m_message->append(m_format);
}
//===============================================

