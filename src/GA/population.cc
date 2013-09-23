/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: population.cc.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#include "population.h"
Population::Population(int num)
  :gene_max(num),IndivNum(9),LossNum(9-3)
{
  Individual *tmp;
  for(int i = 0;i<IndivNum;i++)
    {
      tmp = new Individual(num);
      indiv.push_back(*tmp);
      delete tmp;
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
