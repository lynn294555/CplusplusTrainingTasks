#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>

class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViewWidget(QWidget *parent = 0);

signals:

public slots:
private:
    ViewWidget*		view_widget_;
};

#endif // VIEWWIDGET_H
