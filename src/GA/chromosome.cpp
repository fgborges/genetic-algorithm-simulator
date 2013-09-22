/****************************************
 *  Author: MackRick.
nnn *   Email: mack.sept.public@gmail.com.
 *    File: chromosome.cpp.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: ja_JP.UTF-8.
 * Summary:
 * Last Change: 12-Sep-2013.
 ****************************************/

#include"chromosome.h"
#include<QLine>
#include<QPoint>
#include<QVector>
#include<QDebug>

Chromosome::Chromosome(int num)
{
  int key;
  Gene tmp;
  int i,j;
  
  for (i = 0; i<num ; i++)
    {
      tmp.clear();
      key = qrand()%4+2;
      for(j = 0; j<key; j++)
	{
	  if(key%2)
	    tmp.push_back(true);
	  else
	    tmp.push_back(false);
	}
      for(j = 0; j<8-key; j++)
	{
	  if(key%2)
	    tmp.push_back(false);
	  else
	    tmp.push_back(true);
	}
      gene.push_back(tmp);
      qDebug()<<"+--------Genelate_GENE------------";
      qDebug()<<"|Chromome  :"<<this;
      qDebug()<<"|Alele     :"<<tmp;
      qDebug()<<"+---------------------------------";
    }
}
const Gene& Chromosome::at(int i)const
{
    return gene.at(i);
}
QVector<Gene>::iterator Chromosome::begin()
{
    return gene.begin();
}
QVector<Gene>::iterator Chromosome::end()
{
    return gene.end();
}
void Chromosome::push_back(Gene g)
{
    gene.push_back(g);
}
