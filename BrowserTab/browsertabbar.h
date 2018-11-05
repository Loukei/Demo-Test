#ifndef BROWSERTABBAR_H
#define BROWSERTABBAR_H

#pragma once
#include <QTabBar>

class BrowserTabBar : public QTabBar
{
public:
    explicit BrowserTabBar(QWidget *parent = nullptr);
    ~BrowserTabBar();
protected:
    virtual QSize tabSizeHint(int index) const;
    virtual QSize minimumSizeHint() const;
    //virtual void resizeEvent(QResizeEvent *e);
};

#endif // BROWSERTABBAR_H
