#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>
#include<viewwidget.h>
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
void MainWindow(QWidget *parent = 0);
~MainWindow();
void Init();
private:
ViewWidget *view_widget_;
QAction *figuretool;
QAction *About;
QAction *drawLine;
QAction *drawRectangle;
QAction *drawEllipse;
QAction *Delete;
};
#endif // MAINWINDOW

