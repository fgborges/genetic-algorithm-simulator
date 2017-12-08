/**************************************** 
 *  Author: MackRick.
 *   Email: mack.sept.public@outlook.jp.
 *    File: population.h.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 * Summary: 
 * Last Change: 12-Sep-2013.
 ****************************************/
#ifndef POPLATION_H
#define POPLATION_H
#include"src/GA/individual.h"
#include<QVector>
class Population
{
	public:
		//Constructor
		Population(int num);
		//MainFunction
		void method();
		Individual& at(int i);
		QVector<Individual>::iterator begin();
	private:
		//Function
		void ClossOver();
		void Select();
		void Mutate();
		//Value
		QVector<Individual> indiv;
		//configuration
		const int gene_max;
		const int IndivNum;
		const int LossNum;
};
#endif
