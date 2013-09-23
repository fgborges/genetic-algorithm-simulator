/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: land.h.
 * Project: /home/mackrick/program/school/TMP.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 10-Sep-2013.
 ****************************************/
#pragma once

#include<QVector>
#include<QHash>
#include<QLineF>
#include<QString>
#include "signal.h"
#include<QPair>

//typedef QMap<int,QLineF>::iterator RoadIterator;
#define RoadIterator QHash<int,QLineF>::iterator
typedef QPair<QLineF,int> Road;
struct Land
{
  Land(const QString& filename);
  QHash<int,Road> road;
  int countSignal();
  QVector<Signal> signal;
  int get_random_id()const;
};

