#include"DrawMap.hpp"
#include<QtGui>
#include<QDebug>
#include"Normal.hpp"
#include"defines.hpp"
DrawMap::DrawMap(QWidget *parent):QWidget(parent),land("data.txt"),navi(&land)
{
	timer = new QTimer();
	Init();
	connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
	timer->start(20);
}
void DrawMap::Init()
{
	qsrand(QTime::currentTime().msec());
	for(int i = 0; i < CAR_NUMBER ; i++){
		Car tmp(land.road.at( nrand()%land.road.size() ).l().p1() , land.road.at( nrand()%land.road.size() ).l().p2());
		qDebug()<<"Generated Car"<<tmp.p().x()<<tmp.p().y();
		car.append(tmp);
	}
}
void DrawMap::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QVector<Car>::iterator c_itr;
	QVector<Road>::const_iterator r_itr;
	QSize s(CAR_SIZE,CAR_SIZE);

	painter.setPen(Qt::black);

	for(r_itr=land.road.constBegin();r_itr!=land.road.constEnd();++r_itr)
		painter.drawLine(r_itr->l());
	for(c_itr=car.begin();c_itr!=car.end();++c_itr){
		QRect r(c_itr->p(),s);
		painter.drawRect(r);
	}
	painter.setPen(Qt::red);
	for(c_itr=car.begin();c_itr!=car.end();++c_itr){
		QRect r(c_itr->dest(),s);
		painter.drawRect(r);
	}

}
void DrawMap::onTimer()
{
	QVector<Car>::iterator c_itr;
	for(c_itr=car.begin();c_itr!=car.end();++c_itr)
		navi.CarMove(c_itr); // turn on navi
	update();
}
