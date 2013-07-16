#include"Signal.hpp"
#include<QPoint>
Signal::Signal(const QPoint& p):Object(p)
{
}
Signal::Signal(int x,int y):Object(x,y)
{
}
Signal::Signal():Object()
{
}
void Signal::AppendPattern(int ObjectNumber)
{
	R_ObjNum.append(ObjectNumber);
}
int Signal::getSignal(int ck)const
{
	return R_ObjNum.at(ck%R_ObjNum.size());
}
