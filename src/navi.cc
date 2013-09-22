/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *  File: navi.cc.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/
#include "draw.h"
#include "land.h"
#include <QPair>
#include <QtCore/qmath.h>
#include <QDebug>

inline qreal len (const QPointF& p1,const QPointF& p2)
{
  QPointF d=p2-p1;
  return qSqrt (qPow (d.x(),2)+qPow (d.y(),2));
}
inline qreal angle(const QLineF& l1,const QLineF& l2)
{
  qreal angle = qAbs (l1.angle ()-l2.angle ());
  if (angle > 180)
    angle = 360-angle;
  return angle;
}
inline qreal InPDT (const QPointF& p1,const QPointF& p2,const QPointF& o)
{
  QPointF v1 = p1-o;
  QPointF v2 = p2-o;
  return v1.x()*v2.x()+v1.y()*v2.y();
}

void Draw::SetDiff (Car& car,const QLineF& road)
{
  QPointF diff;
  diff.setX (road.dx()/road.length());
  diff.setY (road.dy()/road.length());
  car.set_diff (diff);
}
void Draw::SetNextRoad (Car& car)
{
  QPair<int,QLineF> result,r;
  result.first=-1;
  static QLineF line;
  qreal min = 10000;
  RoadIterator itr;
  for (itr = land.road.begin () ; itr!=land.road.end () ; ++itr)
    {
      r = qMakePair (itr.key () , itr.value ());
      if (car.get_pos ()==r.second.p1() &&
	  !car.isLog (r.first))
	{
	  line.setP1 (car.get_pos());
	  line.setP2 (car.get_dest());
	  if (angle (r.second,line)<min)
	    {
	      min = angle (r.second,line);
	      result = qMakePair(r.first,r.second);
	    }
	}
    }
  if (result.first == -1)
    {
      int id=car.get_road_id ();
      car.Clear_log ();
      car.Add2Log (id);
    }
  else
    {
      car.Add2Log (result.first);
    }
}
  bool Draw::Reach(const Car& car,const QLineF& road)const
  {
    return len(car.get_pos(),road.p2()) < (len(QPointF(0,0),car.get_diff())+3);
  }
  void Draw::smartAssist(Car& c)
  {
#define ROAD(id) land.road.value(id)
#define REGION(car) (car).get_rect().height()+(car).get_speed()

    QVector<Car>::iterator itr;
    for(itr = car.begin() ; itr != car.end() ; ++itr)
      {
	if(( ROAD (c.get_road_id()).p2() == ROAD (itr->get_road_id()).p1() ) &&
	   ( ROAD (c.get_road_id()).p1() != ROAD (itr->get_road_id()).p2() ) &&
	   ( len(c.get_pos(),itr->get_pos()) < REGION(c) ))
	  {
	    c.set_diff (QPointF(0,0));
	    SetNextRoad (c);
	    return;
	  } 
	if((c.number != itr->number )				&&
	   (c.get_road_id () == itr->get_road_id() )		&&
	   (len (c.get_pos (),itr->get_pos()) < REGION(c) )	&&
	   (InPDT (c.get_pos(),ROAD (c.get_road_id()).p2(),itr->get_pos())<0))
	  {
	    c.set_diff(QPointF(0,0));
	    return;
	  }
      }
#undef ROAD
#undef REGION
  }
  void Draw::CheckSignal (Car& car,long long int l_clock)
  {
    QVector<Signal>::iterator itr = this->land.signal.begin();
    while (itr!=land.signal.end())
      {
	if (len (QPointF (itr->x (),itr->y ()),car.get_pos ())<7)
	  {
	    if (!itr->get_pattern (car.get_road_id(),l_clock))
	      {
		car.set_diff ( QPointF(0,0) );
		car.signal_stop = true;
	      }
	    else
	      {
		car.signal_stop = false;
	      }
	    break;
	  }
	++itr;
      }
  }


