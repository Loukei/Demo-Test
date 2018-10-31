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

signals:
    void addTabClicked(); //see addTabBtn() fun

private:
    /*Child Widgets*/
    QToolButton *addTabButton;
    BrowserTabBar *bTabBar;
};

#endif // BROWSERTAB_H
