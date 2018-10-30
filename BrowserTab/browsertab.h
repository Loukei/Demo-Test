#ifndef BROWSERTAB_H
#define BROWSERTAB_H
#pragma once
#include <QTableWidget>
#include "browsertabbar.h"

class QToolButton;

class BrowserTab : public QTabWidget
{
    Q_OBJECT

public:
    explicit BrowserTab(QWidget *parent = nullptr);
    ~BrowserTab();
    QToolButton* addTabBtn();
    QString showTabBarSize();
    QString showTabPagSize();

signals:
    void addTabClicked(); //see addTabBtn() fun

protected:
//    virtual void resizeEvent(QResizeEvent *e);
//    virtual void tabInserted(int index);
//    virtual void tabRemoved(int index);
//virtual QSize tabSizeHint(int index) const;

private:
    /*Child Widgets*/
    QToolButton *addTabButton;
    BrowserTabBar *p_tabBar;
};

#endif // BROWSERTAB_H
