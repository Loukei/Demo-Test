#include "browsertab.h"
#include <QToolButton>

BrowserTab::BrowserTab(QWidget *parent):
    QTabWidget (parent)
{
    addTabButton = nullptr;
    bTabBar = new BrowserTabBar(this);
    setTabBar(bTabBar);
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
