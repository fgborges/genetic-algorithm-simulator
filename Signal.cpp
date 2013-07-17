#include"Signal.hpp"
#include<QPoint>
#include<QDebug>
Signal::Signal(const QPoint& p):Object(p)
{
}
Signal::Signal(int x,int y):Object(x,y)
{
}
Signal::Signal():Object()
{
}
void Signal::AppendPattern(QVector<int> v)
{
	R_ObjNum.append(v);
}
bool Signal::getSignal(long long int ck,int ObjectNumber)const
{
	QVector<int>::const_iterator itr;
	qDebug()<<"call";
	for(itr=R_ObjNum.at(ck%R_ObjNum.size()).constBegin();itr!=R_ObjNum.at(ck%R_ObjNum.size()).constEnd();++itr)
		if(*itr==ObjectNumber)return true;
	return false;
}
