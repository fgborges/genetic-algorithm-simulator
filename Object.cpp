#include"Object.hpp"
#include<QDebug>
static long long int g_ObjNum = 0;
int g_mkObjNum()
{
	g_ObjNum++;
	return g_ObjNum;
}
Object::Object(int x,int y)
{
	point.setX(x);
	point.setY(y);
	ObjectNumber=g_mkObjNum();
}
Object::Object(const QPoint& a):point(a)
{
	ObjectNumber=g_mkObjNum();
}
Object::Object(const QPoint& p1,const QPoint& p2)
{
	ObjectNumber=g_mkObjNum();
	line.setPoints(p1,p2);
}
Object::Object(const QLine& a):line(a)
{
	ObjectNumber=g_mkObjNum();
}
Object::Object()
{
	ObjectNumber=g_mkObjNum();
}
void Object::moveTo(const QPoint& a)
{
//	point.setX(a.x());
//	point.setY(a.y());
	point = a;
}
void Object::moveTo(int x,int y)
{
	point.setX(x);
	point.setY(y);
}
void Object::moveTo(const QPoint& p1,const QPoint& p2)
{
	line.setP1(p1);
	line.setP2(p2);
}
void Object::setPoint(const QPoint& a)
{
	moveTo(a);
}
void Object::setPoint(int x,int y)
{
	moveTo(x,y);
}
void Object::setLine(const QPoint& p1,const QPoint& p2)
{
	moveTo(p1,p2);
}
QLine Object::l()const
{
	return line;
}
QPoint Object::p()const
{
	return point;
}
QLine& Object::rl()
{
	return line;
}
QPoint& Object::rp()
{
	return point;
}
long long int Object::ObjNum()const
{
	return ObjectNumber;
}

