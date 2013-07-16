#include<QPoint>
#include<QDebug>
#include"Car.hpp"
Car::Car(const QPoint& pos,const QPoint& a)
		:Object(pos),d(QPoint(0,0)),destination(a)
{
	RoadObjectNumber = 0;
	sbmod = false;
}
Car::Car(int x,int y,const QPoint& a)
		:Object(x,y),d(QPoint(0,0)),destination(a)
{
	RoadObjectNumber = 0;
	sbmod = false;
}
Car::Car():Object()
{
}
void Car::set_dX(int x)
{
	d.setX(x);
}
void Car::set_dY(int y)
{
	d.setY(y);
}
void Car::setD(const QPoint& a)
{
	d = a;
}
void Car::set_dest(const QPoint& dest)
{
	destination = dest;
}
void Car::move()
{
	moveTo(p()+d);
}
QPoint Car::dest() const 
{
	return destination;
}
bool Car::first()const
{
	if(d == QPoint(0,0))
		return true;
	else
		return false;
}
void Car::hasObjNum(long long int n)
{
	RoadObjectNumber = n;
}
long long int Car::R_ObjNum()const
{
	return RoadObjectNumber;
}
void Car::set_maindest(const QPoint& p)
{
	main_destination = p;
}
QPoint Car::maindest()const
{
	return main_destination;
}
