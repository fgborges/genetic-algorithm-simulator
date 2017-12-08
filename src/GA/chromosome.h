/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: chromosome.h.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 *
 * Summary: 染色体クラスです。Vectorを使う
 * 　　　　 ことで個体のシュミレーションの
 * 　　　　 幅を可変にしています。
 *
 * Last Change: 12-Sep-2013.
 ****************************************/
#pragma once
#include<QVector>

typedef QVector<bool> Gene;

class Chromosome 
{
 public:
  Chromosome(int num);
  const Gene& at(int i)const;
  QVector<Gene>::iterator begin();
  QVector<Gene>::iterator end();
  void push_back(Gene g);
 private:
  QVector<Gene> gene;
};	 
