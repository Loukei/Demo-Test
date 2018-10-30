#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "browsertab.h"
#include <QLabel>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)/*,*/
//    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    setWindowTitle(tr("Browser Tab widget"));

    tabwidget = new BrowserTab(this);
    tabwidget->addTab(new QLabel("some content",tabwidget),
                      QString("Loooooooooooooooooong Title"));
    tabwidget->addTabBtn();
    connect(tabwidget,&BrowserTab::addTabClicked,this,&MainWindow::newTab);
    connect(tabwidget,&BrowserTab::tabCloseRequested,this,&MainWindow::closeTab);
    setCentralWidget(tabwidget);
}

MainWindow::~MainWindow()
{
//    delete ui;
}

void MainWindow::newTab()
{
    tabwidget->addTab(new QLabel("some content",tabwidget),
                      QString("Tab %1").arg(tabwidget->count()+1));
}

void MainWindow::closeTab(int index)
{
    tabwidget->removeTab(index);
}
