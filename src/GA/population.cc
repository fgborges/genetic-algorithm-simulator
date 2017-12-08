/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: population.cc.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#include "population.h"
#include <QDebug>
Population::Population(int num)
  :gene_max(num),
   IndivNum(9),
   LossNum(6)
{
  for(int i = 0;i<9;i++)
    {
      Individual tmp(num);
      indiv.push_back(tmp);
    }
}
QVector<Individual>::iterator Population::begin()
{
  return indiv.begin();
}
Individual& Population::at(int i)
{
  return indiv[i];
}
