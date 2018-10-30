#include "browsertab.h"
#include <QToolButton>

BrowserTab::BrowserTab(QWidget *parent):
    QTabWidget (parent)
{
    addTabButton = nullptr;
    p_tabBar = new BrowserTabBar(this);
    setTabBar(p_tabBar);

    setMovable(true);
    setTabsClosable(true);
}

BrowserTab::~BrowserTab()
{
    delete addTabButton;
}

QToolButton* BrowserTab::addTabBtn()
{
    /*Initial "addTabButton" and return pointer*/
    if(addTabButton == nullptr)
    {
        addTabButton = new QToolButton(this);
        addTabButton->setText("+");
        addTabButton->setShortcut(QKeySequence::AddTab);
        addTabButton->setAutoRaise(true);
        connect(addTabButton,&QToolButton::clicked,this,&BrowserTab::addTabClicked);
        setCornerWidget(addTabButton,Qt::TopRightCorner);
    }
    return addTabButton;
}

QString BrowserTab::showTabBarSize()
{
    QString info("");
    return info;
}

QString BrowserTab::showTabPagSize()
{
    return QString("TabWidget:\n"
                   "Width: %1\n"
                   "High: %2").arg(this->width()).arg(this->height());
}

//void BrowserTab::resizeEvent(QResizeEvent *e)
//{
//    QTabWidget::resizeEvent(e);
//}

//void BrowserTab::tabInserted(int index)
//{
//    QTabWidget::tabInserted(index);
//}

//void BrowserTab::tabRemoved(int index)
//{
//    QTabWidget::tabRemoved(index);
//}
