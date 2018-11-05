#include "browsertab.h"
#include <QToolButton>

BrowserTab::BrowserTab(QWidget *parent):
    QTabWidget (parent)
{
    addTabButton = nullptr;
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

void BrowserTab::resizeEvent(QResizeEvent *event)
{
    QTabWidget::resizeEvent(event);
    setTabBarSize();
}

void BrowserTab::tabInserted(int index)
{
    QTabWidget::tabInserted(index);
    setTabBarSize();
}

void BrowserTab::tabRemoved(int index)
{
    QTabWidget::tabRemoved(index);
    setTabBarSize();
}

void BrowserTab::setTabBarSize()
{
//    int minWidth = this->minimumWidth();
    int minWidth = 200;
    int blanksize = 40;
    int tabWidth = int ((width() - blanksize) / count());
    if(tabWidth < minWidth)
    {
        tabWidth = minWidth;
    }

    setStyleSheet( styleSheet() +
                  "QTabBar::tab {""width: " +
                  QString::number(tabWidth) +
                  "px; }" );
}


