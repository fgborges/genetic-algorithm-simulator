/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: signal.cc.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/

#include "signal.h"
#include<QDebug>
#include<QVector>

Signal::Signal(const qreal x,const qreal y)
    :QPointF(x,y)
{}

void Signal::set_pattern(const int id,QVector<bool> p)
{
  this->pattern.insert(id,p);
}

bool Signal::get_pattern(const int id,const int index)const
{
  return pattern.value(id).at(index);
}
QMap< int,QVector<bool> >::iterator Signal::begin()
{
  return pattern.begin();
}
QMap< int,QVector<bool> >::iterator Signal::end()
{
  return pattern.end();
}
int Signal::size()const
{
  qDebug()<<pattern.size();
  return pattern.size();
}
