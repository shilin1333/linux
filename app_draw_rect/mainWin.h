#ifndef MAINWINDOW_H
#define MAINWINDOW_H 
#include <QtGui/QPushButton> 
#include <QWidget> 
#include <QPainter> 
#include <QtGui>

#include <QGraphicsItem> 
#include <QWSServer>
#include <QMouseEvent>
class MyMainWindow:public QWidget 
{ 
	Q_OBJECT 
public: 
	MyMainWindow(QWidget *parent = 0); 
	virtual ~MyMainWindow(); 
private slots:
   	void handleButton(); 
	void handleButton_stop();
private: 
	QPushButton *m_button; 
	QPushButton *m_button_stop; 
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *); 
	void mouseMoveEvent(QMouseEvent *);
	QPainter *paint; 
	int start_flag;
	int x;
	int y;
	int x_mouse;
	int y_mouse;
}; 

#endif
