#ifndef BROWSERTAB_H
#define BROWSERTAB_H
#pragma once
#include <QTableWidget>

class QToolButton;
class BrowserTab : public QTabWidget
{
    Q_OBJECT

public:
    explicit BrowserTab(QWidget *parent = nullptr);
    ~BrowserTab();
    QToolButton& addTabBtn();
    void setTabBarExpand(bool boolen);

signals:
    void addTabClicked(); //see addTabBtn() fun

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void tabInserted(int index);
    virtual void tabRemoved(int index);

private:
    /*Child Widgets*/
    QToolButton *addTabButton;

    /*Property*/
    bool tabBarExpand;

    void averageTabBarSize();
    void moveAddTabButon();
};

#endif // BROWSERTAB_H
