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

bool Signal::sig(int ck)
{
	return signal_pattern[ck];
}
