#include "browsertab.h"
#include <QToolButton>
#include <QDebug>

BrowserTab::BrowserTab(QWidget *parent):
    QTabWidget (parent)
{
    qDebug() << "In BrowserTab():" << endl;
    addTabButton = nullptr;
    tabBarExpand = false;
    setMovable(true);
    setTabsClosable(true);
    setElideMode(Qt::ElideRight);
}

BrowserTab::~BrowserTab()
{
    delete addTabButton;
}

QToolButton& BrowserTab::addTabBtn()
{
    /*Initial "addTabButton" and return pointer*/
    qDebug() << "In addTabBtn():" << endl;
    if(addTabButton == nullptr)
    {
        addTabButton = new QToolButton(this);
        addTabButton->setText("+");
        addTabButton->setShortcut(QKeySequence::AddTab);
        addTabButton->setAutoRaise(true);
        connect(addTabButton,&QToolButton::clicked,this,&BrowserTab::addTabClicked);
        //setCornerWidget(addTabButton,Qt::TopRightCorner);
        moveAddTabButon();
    }
    return *addTabButton;
}

void BrowserTab::setTabBarExpand(bool boolen)
{
    tabBarExpand = boolen;
}

void BrowserTab::resizeEvent(QResizeEvent *event)
{
    qDebug() << "In resizeEvent():" << endl;
    QTabWidget::resizeEvent(event);
    if(tabBarExpand)
    {
        averageTabBarSize();
    }
    if(addTabButton)
    {
        moveAddTabButon();
    }

}

void BrowserTab::tabInserted(int index)
{
    qDebug() << "In tabInserted():" << endl;
    QTabWidget::tabInserted(index);
    if(tabBarExpand)
    {
        averageTabBarSize();
    }
    if(addTabButton)
    {
        moveAddTabButon();
    }
}

void BrowserTab::tabRemoved(int index)
{
    qDebug() << "In tabRemoved():" << endl;
    QTabWidget::tabRemoved(index);
    if(tabBarExpand)
    {
        averageTabBarSize();
    }
    if(addTabButton)
    {
        moveAddTabButon();
    }
}

void BrowserTab::averageTabBarSize()
{
    qDebug() << "In averageTabBarSize()" << endl;
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

void BrowserTab::moveAddTabButon()
{
    qDebug() << "In moveAddTabButon():" << endl;
    int sum = 0;
    for(int i=0;i < count();i++)
    {
        sum += tabBar()->tabRect(i).width();
    }
//    int sum = width();
    int yPos = tabBar()->geometry().top();
    int xPos = tabBar()->width();

    qDebug() << "sum:" << sum << endl
             << "tabwidget width:" << width() << endl
             << "xPos:" << xPos << endl
             << "yPos:" << yPos << endl;

    if(sum > xPos)
    {
        addTabButton->move(xPos,yPos);
        qDebug() << "(xPos,yPos)=" << "(" << xPos << "," << yPos << ")" <<endl;
    }
    else
    {
        addTabButton->move(sum,yPos);
         qDebug() << "(sum,yPos)=" << "(" << sum << "," << yPos << ")" <<endl;
    }
}
