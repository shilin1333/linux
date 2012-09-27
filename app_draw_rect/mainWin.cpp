#include <QApplication> 
#include "mainWin.h"

void MyMainWindow::paintEvent(QPaintEvent *) 
{ 
	paint=new QPainter; 
	paint->begin(this); 
	paint->setPen(QPen(Qt::blue,4,Qt::DashLine)); //设置画笔形式 
	if(start_flag)
	{
		x += 20;
		if(x == 800)
		{
			x = 0;
			y += 80;
		}
		if(y == 480)
		{
			y = 0;
		}
	}
	//paint->setBrush(QBrush(Qt::red,Qt::SolidPattern)); //设置画刷形式 
	//paint->drawRect(20,20,160,160); 
	paint->drawRect(x, y, 80, 80);
	paint->setPen(QPen(Qt::red,4,Qt::DashLine));
	paint->drawRect(x_mouse, y_mouse, 40, 40);
	paint->end(); 
} 


MyMainWindow::MyMainWindow(QWidget *parent):QWidget(parent) 
{ 
	x = 0;
	y = 0;
	start_flag = 0;
	setGeometry(0,0,800,480); 
	m_button = new QPushButton("start", this); 
	m_button->setGeometry(QRect(QPoint(50, 100),
                                 QSize(150, 40))); 
	connect(m_button, SIGNAL(released()), this, SLOT(handleButton())); 

	m_button_stop = new QPushButton("stop", this);
	m_button_stop->setGeometry(QRect(QPoint(50, 300), QSize(150,40)));
	connect(m_button_stop, SIGNAL(released()), this, SLOT(handleButton_stop())); 
	
//	update();
	QTimer *timer = new QTimer(this);

        connect(timer, SIGNAL(timeout()), this, SLOT(update()));

        timer->start(100);
	QWSServer::setBackground(QColor(0,0,0,0));
	setAttribute(Qt::WA_TranslucentBackground);
	setMouseTracking(true);
	setCursor(Qt::BlankCursor);   //hide cursor
	//setCursor(Qt::ArrowCursor);   
	//QPushButton *pushButton = new QPushButton(tr("&Normal Button"));
}
#if 1
void MyMainWindow::mousePressEvent(QMouseEvent *m)
{
	x_mouse = m->x();
	y_mouse = m->y();
	//qDebug("shilin1\n");
}
#endif

void MyMainWindow::mouseMoveEvent(QMouseEvent *m)
{
	x_mouse = m->x();
	y_mouse = m->y();

	//qDebug("shilin2\n");
}

void MyMainWindow::handleButton()
{
    
    //m_button->setText("Example");

	start_flag = 1;
	qDebug("btn start\n");
	system("./saMmapDisplay &");
    //m_button->resize(100,100);
} 

void MyMainWindow::handleButton_stop()
{
    
    //m_button->setText("Example");

	start_flag = 0;
	qDebug("btn stop\n");
	system("kill `cat /var/run/camera.pid`");
    //m_button->resize(100,100);
} 
MyMainWindow::~MyMainWindow()
{

} 
int main(int argc,char **argv) 
{ 
	QApplication a(argc,argv); 
	MyMainWindow w; 
	w.show(); 
	//repaint();
	return a.exec(); 
}

