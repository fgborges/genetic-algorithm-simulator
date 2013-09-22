/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: individual.cpp.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: ja_JP.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/
#include"src/GA/individual.h"

Individual::Individual (int num)
  :Chromosome(num)
{
}

int Individual::getEval ()const
{
  return eval;
}

void Individual::setEval (int eval)
{
  this->eval = eval;
}

bool Individual::operator == (const Individual& i)const
{
  return this->eval == i.eval;
}
bool Individual::operator > (const Individual& i)const
{
  return this->eval > i.eval;
}
bool Individual::operator < (const Individual& i)const
{
  return this->eval < i.eval;
}
