#include "browsertabbar.h"

BrowserTabBar::BrowserTabBar(QWidget *parent):
    QTabBar (parent)
{
    //setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred); //doesnt work
}

BrowserTabBar::~BrowserTabBar()
{

}

QSize BrowserTabBar::tabSizeHint(int index) const
{
    QSize size = QTabBar::tabSizeHint(index);
    int width = int(1000 / this->count());
    return QSize(width,size.height());
}

QSize BrowserTabBar::minimumSizeHint() const
{
    QSize size = QTabBar::minimumSizeHint();
    return QSize(200,size.height());
}

//void BrowserTabBar::resizeEvent(QResizeEvent *e)
//{
//    QTabBar::resizeEvent(e);
//}
