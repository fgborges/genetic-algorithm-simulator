#include"Road.hpp"
#include<qmath.h>
#include<QPoint>
#include<QLine>
#include<QDebug>
Road::Road(const QPoint& p1,const QPoint& p2):Object(p1,p2)
{
}
Road::Road(const QLine& l):Object(l)
{
}
Road::Road():Object()
{
}

int InPDT(const QPoint& v1,const QPoint& v2,const QPoint& o)
{
	return (v1.x()-o.x())*(v2.x()-o.x())+(v1.y()-o.y())*(v2.y()-o.y());
}
int lenPow2(const QPoint& p1,const QPoint& p2)
{
	return qPow(static_cast<qreal>(p1.x()-p2.x()),2)+qPow(static_cast<qreal>(p1.y()-p2.y()),2);
}
bool Road::online(const QPoint& p)const
{
	int pdt = InPDT(l().p1(),l().p2(),p);
	bool ans;
	if( pdt<0 && qPow(static_cast<qreal>(pdt),2)==lenPow2(Object::l().p1(),p)*lenPow2(Object::l().p2(),p) )
		ans = true;
	else if(l().p1()==p||l().p2()==p)
		ans =  true;
	else
		ans =  false;
//	qDebug()<<ans;
	return ans;

}
