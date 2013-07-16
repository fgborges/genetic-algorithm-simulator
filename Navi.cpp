#include<QPoint>
#include<QDebug>
#include"Navi.hpp"
#include"Land.hpp"
#include"Road.cpp"//for lenPow2()
#include<qmath.h>
#include"Normal.hpp"
#include"defines.hpp"
static int miss = 1;
static int goal = 1;
Navi::Navi(Land *ptr):land_ptr(ptr)
{
}
{
}
bool destribute(const QPoint& p,const QPoint& q)
{
	QPoint d=p-q;
	if(qAbs(d.x())<CAR_SPEED+1&&qAbs(d.y())<CAR_SPEED+1)
		return true;
	else
		return false;
}
int make_dx(QVector<Road>::const_iterator itr)
{
	if(itr->l().p2().x()-itr->l().p1().x()==0)
	{
		return 0;
	}else{
		int dx=(itr->l().p2().x()-itr->l().p1().x())/qAbs(itr->l().p2().x()-itr->l().p1().x());
		return dx/qAbs(dx)*CAR_SPEED;
	}
}
int make_dy(QVector<Road>::const_iterator itr)
{
	if(itr->l().p2().y()-itr->l().p1().y()==0){
		return 0;
	}else{
		int dy=(itr->l().p2().y()-itr->l().p1().y())/qAbs(itr->l().p2().y()-itr->l().p1().y());
		return dy/qAbs(dy)*CAR_SPEED;
	}
}
void Navi::CarMove(QVector<Car>::iterator car)
{
	QVector<Road>::const_iterator itr1,itr2;
	QVector<QPoint>::const_iterator itr3,itr4;
	bool p_flag = false;
	bool g_flag =false;
	bool redo = false;
	QPoint log_point(0,0);
/*DON'T MODIFIED!!!*/
/***************************************************************************************/
/**/	for(itr1=land_ptr->road.constBegin();itr1!=land_ptr->road.constEnd();++itr1)
/**/	{
/**/		if(redo){
/**/			--itr1;
/**/		}
/**/		if(car->R_ObjNum()==itr1->ObjNum()||car->R_ObjNum()==0)
/**/			if(car->R_ObjNum()==itr1->ObjNum()||itr1->online(car->p()))
/**/			{
/**/				car->hasObjNum(itr1->ObjNum());
/**/				//CarMove
/**/				{
/**/					car->move();
/**/					if(car->first())
/**/					{
/**/						car->setD(QPoint(make_dx(itr1),make_dy(itr1)));
/**/					}
/**/				}
/**/				if(destribute(itr1->l().p2(),car->p()))
/**/				{
/**/					for(itr3=car->log.constBegin();itr3!=car->log.constEnd();++itr3)
/**/						if(*itr3 == itr1->l().p2()){
/**/							p_flag = true;
/**/							break;
/**/						}else{
/**/							p_flag = false;
/**/						}
/**/					//Car force into p2
/**/					{
/**/						car->setPoint(itr1->l().p2());
/**/						log_point = itr1->l().p2();
/**/						car->log.append(log_point);
/**/					}
/**/					//Check whether it is destination of car
/**/					if((itr1->l().p2() == car->dest()))
/**/					{
/**/						if(itr1->l().p2() == car->maindest())
/**/							qDebug()<<"Goal"<<goal++;
/**/						g_flag = true;
/**/						car->log.clear();
/**/						QPoint destination=car->p();
/**/						while(destination==itr1->l().p2())
/**/						{
/**/							destination = land_ptr->road.at(nrand()%land_ptr->road.size()).l().p2();
/**/						}
/**/						if(car->sbmod){
/**/							destination = car->maindest();
/**/							car->sbmod = false;
/**/						}
/**/						car->set_maindest(destination);
/**/						car->set_dest(destination);
/**/					}
/**/					//Search next p2
/**/					int min = 10000000;
/**/					for(itr2=land_ptr->road.constBegin();itr2!=land_ptr->road.constEnd();++itr2)
/**/						if(itr2->l().p1()==car->p())
/**/						{
/**/							int pdt;
/**/							pdt = InPDT(itr2->l().p2(),itr1->l().p1(),car->p());
/**/							if((!(qPow(pdt,2)==lenPow2(itr2->l().p2(),car->p())*lenPow2(itr1->l().p1(),car->p())&&pdt>0))||g_flag)
/**/							{
/**/								
/**/								if(!p_flag)
/**/								{
/**/									int len = qSqrt(lenPow2(itr2->l().p2(),car->dest()));
/**/									if(len<min)//it's avabable when it is x=0 or y=0,but other is not.
/**/									{
/**/										min=len;
/**/										car->hasObjNum(itr2->ObjNum());
/**/										car->setD(QPoint(make_dx(itr2),make_dy(itr2)));
/**/										p_flag = false;
/**/									}
/**/								}
/**/								else
/**/								{
/**/									bool matched = true;
/**/									for(itr4=car->log.constBegin();itr4!=car->log.constEnd();++itr4)
/**/										if(*itr4 == itr2->l().p2())
/**/											matched = false;
/**/									if(matched){
/**/											car->hasObjNum(itr2->ObjNum());
/**/											car->setD(QPoint(make_dx(itr2),make_dy(itr2)));
/**/											car->log.clear();
/**/											p_flag = false;
/**/											break;
/**/									}
/**/								}
/**/							}
/**/						}
/**/					if(p_flag){
/**/						if(car->sbmod)qDebug()<<"miss"<<miss++;
/**/						car->log.clear();
/**/						QPoint destination2=car->p();
/**/						while(destination2==car->p())
/**/						{
/**/							destination2 = land_ptr->road.at(qrand()%land_ptr->road.size()).l().p2();
/**/						}
/**/						car->set_maindest(car->dest());
/**/						car->sbmod = true;
/**/						p_flag=false;
/**/						g_flag=true;
/**/						car->set_dest(destination2);
/**/						redo = true;
/**/						qDebug()<<itr1->l().p1().x()<<itr1->l().p1().y()<<itr1->l().p2().x()<<itr1->l().p2().y();
/**/						continue;
/**/					}else
/**/						break;
/**/					
/**/				}
/**/		}
/**/	}
/****************************************************************************************************/
}
