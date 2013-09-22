
/****************************************
 *  Author: $AUTHOR.
 *   Email: $MAIL.
 *    File: signal.h.
 * Project: /home/mackrick/tmp/beta1/src.
 *  Coding: ja_JP.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#pragma once
#include<QPointF>
#include<QMap>
#include<QVector>
class Signal : public QPointF
{
 public:
  Signal(const qreal x = 0,const qreal y=0);
  void set_pattern(const int id,QVector<bool> pattern);
  bool get_pattern(const int id,const int index)const;

  QMap< int,QVector<bool> >::iterator end();
  QMap< int,QVector<bool> >::iterator begin();
  int size()const;
 private:
  QMap< int,QVector<bool> > pattern;
};
