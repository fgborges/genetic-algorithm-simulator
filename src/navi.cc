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

int Draw::Count_car(int key)
{
  int cnt=0;
  for (auto c : car)
    if (c.get_road_id () == key) cnt++;
  return cnt;
}
void Draw::SetNextRoad (Car& c)
{
  QPair<int,QLineF>	result,r;
  QLineF		line;
  qreal			min = 10000;
  int			num = 0;
  result.first = -1;
  for (auto r=land.road.begin () ; r!=land.road.end () ; ++r)
    {
      if (r.value().first.p1() == c.get_pos ()	&&
	  !c.isLog (r.key()))
	{
	  line.setP1 (c.get_pos());
	  line.setP2 (c.get_dest());
	  if (angle (r.value().first,line)<min)
	    {
	      min    = angle (r.value().first,line);
	      result = qMakePair (r.key(),r.value().first);
	      num = r.value ().second;
	    }
	}
    }
  if (result.first == -1)
    {
      int id = c.get_road_id ();
      c.set_dest (land.road.value (land.get_random_id()).first.p2 ());
      c.Clear_log ();
      c.set_num(qrand ()%land.road.value(id).second);
      c.Add2Log(id);
    }
  else
    {
      c.Add2Log (result.first);
      c.set_num (qrand ()%num);
    }
}
bool Draw::Reach (const Car& car,const QLineF& road)const
{
  return len(car.get_pos(),road.p2()) < (len(QPointF(0,0),car.get_diff())+3);
}
void Draw::smartAssist (Car& c)
{
#define ROAD(id) land.road.value(id).first
#define REGION(car) (car).get_rect().height()+(car).get_speed()+2
  QVector<Car>::iterator itr;
  for (itr = car.begin() ; itr != car.end() ; ++itr)
    {
      if ((ROAD (c.get_road_id()).p2() == ROAD (itr->get_road_id()).p1()) &&
	  (ROAD (c.get_road_id()).p1() != ROAD (itr->get_road_id()).p2()) &&
	  (len(c.get_pos(),itr->get_pos()) < REGION(c)))
	{
	  c.set_diff (QPointF(0,0));
	  SetNextRoad (c);
	  return;
	} 
      if ((c.number != itr->number )				&&
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
	      if(!car.signal_stop)car.log_pop_back();
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


