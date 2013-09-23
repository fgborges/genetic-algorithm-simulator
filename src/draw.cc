/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: draw.cc.
 * Project: /home/mackrick/beta1/src.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 13-Sep-2013.
 ****************************************/
#include "draw.h"
#include "land.h"
#include "signal.h"
#include<QRectF>
#include<QLineF>
#include<QPointF>
#include<QPainter>
#include<QTimer>
#include<QWidget>
#include<QVector>
#include<QDebug>
#include<QtCore/qmath.h>
#include"src/GA/population.h"
#include "src/GA/individual.h"
#include "src/GA/chromosome.h"
static const int road_range = 5;
inline QPointF SignalPos(const QLineF& line)
{
  const int	l   = 20;
  QPointF	vec = line.p2()-line.p1();
  QPointF	pos;
  qreal		r;
  r=-qAtan2(road_range,l);
  vec/=vec.manhattanLength();
  pos.rx()=line.p1().x()+(qSqrt(road_range*road_range/4+l*l)*(vec.x()*qCos(r)-vec.y()*qSin(r)));
  pos.ry()=line.p1().y()+(qSqrt(road_range*road_range/4+l*l)*(vec.x()*qSin(r)+vec.y()*qCos(r)));
  return pos;
}
inline qreal len(const QPointF& p1,const QPointF& p2)
{
    QPointF d=p2-p1;
    return qSqrt(qPow(d.x(),2)+qPow(d.y(),2));
}
inline QPointF make_road_d(const QLineF& road)
{
  QPointF d(road.dx(),road.dy());
  d/=road.length();
  return d*3;
}
QVector<QLineF> multiline (const QHash<int,Road>& l)
{
  QVector<QPair<QLineF,int> > list;
  QVector<QLineF>	tmp;
  QLineF		line;
  QPointF		diff;
  for (auto r : l)
    list.push_back(r);
  for (auto i : list)
    {
      diff = QPointF(-i.first.dy(),i.first.dx());
      QPointF diff2 = diff;
      diff /= qSqrt(diff2.x()*diff2.x()+diff2.y()*diff2.y());
      diff *= 5;
      for (int j=0;j<i.second;j++)
	{
	  line.setP1 (i.first.p1()-diff*(2*j+1));
 	  line.setP2 (i.first.p2()-diff*(2*j+1));
	  tmp.push_back (line);
	}
    }
  return tmp;
}
Draw::Draw(QString	filename,
           int		car_number,
           QString	img,
           QWidget*	parent)
  :QWidget(parent),
   land(filename),
   img(img),
   car_number(car_number),
   g_clock(0),
   index(0)
{
  InitCar();
  pop	 = new  Population(land.countSignal());
  InitSignal(*(pop->begin()));
  map	 = multiline(land.road);
  timer	 = new QTimer();
  timer->start(20);
  connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
  timer2 = new QTimer();
  timer2->start(500);
  connect(timer2,SIGNAL(timeout()),this,SLOT(onTimer2()));
}
void Draw::InitCar()
{
  int id;
  int size;
  this->car.clear();
  for(int i = 0 ; i< car_number ; i++)
    {
      id = land.get_random_id();
      Car tmp(id,land.road.value(id).first.p1());
      tmp.set_dest(land.road[land.get_random_id()].first.p2());
      SetDiff(tmp,land.road[id].first);
      size = qrand()%3;
      tmp.set_rect(QRectF(0,0,size+2,size+2));
      tmp.set_speed((qrand()%150)/100.0+0.9);
      tmp.number = i;
      qDebug()<<"+------Car_Generate-------";
      qDebug()<<"|num  :"<<tmp.number;
      qDebug()<<"|pos  :"<<tmp.get_pos();
      qDebug()<<"|id   :"<<tmp.get_road_id();
      qDebug()<<"|speed:"<<tmp.get_speed();
      qDebug()<<"|size :"<<tmp.get_rect();
      qDebug()<<"+-------------------------";
      qDebug();
      car.append(tmp);
    }
  CAR_SIZE=5;
}
void Draw::InitSignal (Individual& indiv)
{
  QVector<Signal>::iterator	itr	= land.signal.begin();
  QVector<Gene>::iterator	pattern = indiv.begin();
  while (itr!=land.signal.end())
    {
      qDebug()<<"+--------Signal_Generate---------";
      qDebug()<<"|pos     :"<<itr->x()<<','<<itr->y();
      for (auto r = land.road.begin () ;r != land.road.end () ; ++r)
	{
	  if (itr->x() == r.value ().first.p1 ().x () &&
	      itr->y() == r.value ().first.p1 ().y ())
	    {
	      qDebug()<<"|connect :"<<r.key ();
	      qDebug()<<"|pattern :"<<*pattern;
	      itr->set_pattern (r.key(),*pattern);
	      ++pattern;
	    }
	}
      qDebug()<<"+--------------------------------";
      ++itr;
    }
}
void Draw::paintEvent (QPaintEvent *)
{
  QPainter	painter(this);
  QRectF	rect_dest(0,0,10,10);
  QRectF	rect_pos;
  QLineF	line;
  QPointF	d(0,0);
  QPointF	p;
  painter.setPen(Qt::gray);

  if(img!="none")painter.drawImage(QPoint(5,-10),QImage(img));
  //Drawing Road
  painter.drawLines (this->map);

  //Drawing Car position and destination
  for (auto c : car)
    {
      d=make_road_d (land.road [c.get_road_id()].first);
      d *= c.get_num()+1;
      rect_pos=c.get_rect();
      rect_pos.moveCenter (c.get_pos ()+QPointF(d.y(),-d.x())*road_range/2);
      painter.setPen(Qt::black);
      painter.drawRect(rect_pos);
      rect_pos.moveCenter (c.get_dest ());
      painter.setPen(Qt::red);
      painter.drawRect(rect_pos);
    }
    //Drawing Signal
  for (auto s : land.signal)
    {
      QMap<int,QVector<bool> >::iterator pattern;
      for(pattern=s.begin(); pattern!=s.end(); ++pattern)
	{
	  if(s.get_pattern(pattern.key(),g_clock%8))
	    {
	      painter.setPen(Qt::blue);
	      painter.setBrush(Qt::blue);
	    }
	  else
	    {
	      painter.setPen(Qt::red);
	      painter.setBrush(Qt::red);
	    }
	  QPointF pos=SignalPos(land.road[pattern.key()].first);
	  painter.drawEllipse(pos.x()-3,pos.y()-3,6,6);
	}
    }
  painter.setPen(Qt::black);
  painter.setBrush(Qt::black);
}
void Draw::onTimer()
{
  QLineF r;
  for (auto& c : car)
    {
      c.moveTo (c.get_pos () + c.get_diff ());
      r = land.road [c.get_road_id ()].first;
      SetDiff (c,r);

      if (Reach(c,r))
	{
	  c.moveTo(r.p2 ());
	  if (c.get_pos () == c.get_dest ())
	    {
	      c.set_dest (land.road [land.get_random_id ()].first.p2 ());
	      c.Clear_log();
	    }
	  SetNextRoad (c);
	  CheckSignal (c,g_clock%8);
	}
      if (c.signal_stop)
	{
	  CheckSignal (c,g_clock%8);
	}
      smartAssist(c);
    }
  if(g_clock%10 == 0)
    {
      int eval;
      pop->at(index).setEval(eval=Evaluate());
      evalChanged(eval);
      index++;
      if(index==9)
	{
	  pop->method();
	  index=0;
	}
      qDebug()<<"NewSignal PATTERN";
      if(index<9)
	{
	  Individual tmp = pop->at(index);
	  InitSignal(tmp);
	}
      g_clock++;
    }
  update();
}
void Draw::onTimer2()
{
  g_clock++;
}
void Draw::reset()
{
  InitCar();
  return;
}
void Draw::change_speed(int speed)
{
  timer->stop();
  timer->start(speed);
  return;
}
