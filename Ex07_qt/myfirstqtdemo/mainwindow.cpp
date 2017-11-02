#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include "mainwindow.h"
void MainWindow::MainWindow(QWidget *parent = 0)
{
    void Init();
}
MainWindow::~MainWindow()
{ }

void MainWindow::Init()
{
    view_widget_ = new ViewWidget();
    setCentralWidget(view_widget_);
    setWindowTitle(tr("mainwindow"));
    QMenu *figure_tool=menuBar()->addMenu(tr("Figure Tool"));
    //figure_tool->addAction(figuretool);
    About = new QAction(tr("&About"),this);
    About->setShortcuts(QKeySequence::Open);
    About->setStatusTip(tr("Open an existing file"));
    drawLine=new QAction(tr("&Line"),this);
    drawRectangle=new QAction(tr("&Rectangle"),this);
    drawEllipse=new QAction(tr("&Ellipse"),this);
    Delete=new QAction(tr("&Delete"),this);
    connect(About, &QAction::triggered, this, &MainWindow::open);
    QToolBar *toolBar_1 =addToolBar(tr("&About"));
    QToolBar *toolBar_2 =addToolBar(tr("&Line"));
    QToolBar *toolBar_3 =addToolBar(tr("&Rectangle"));
    QToolBar *toolBar_4 =addToolBar(tr("&Ellipse"));
    QToolBar *toolBar_5 =addToolBar(tr("&Delete"));
    toolBar_1->addAction(About);
    toolBar_2->addAction(drawLine);
    toolBar_3->addAction(drawRectangle);
    toolBar_4->addAction(drawEllipse);
    toolBar_5->addAction(Delete);
    statusBar() ;

}
