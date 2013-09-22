/****************************************
 *  Author: MackRick.
 *   Email: mack.sept.public@gmail.com.
 *    File: individual.h.
 * Project: /home/mackrick/beta1/src/GA.
 *  Coding: en_US.UTF-8.
 * Summary: 個体クラスです。染色体クラスを
 * 　　　　 継承し実際にアルゴリズムでは
 * 　　　　 こちらからデータを操作してもら
 * 　　　   もらうことになります。
 * Last Change: 12-Sep-2013.
 ****************************************/
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include"chromosome.h"
class Individual : public Chromosome
{
	public:
		Individual(int num=0);
		int getEval()const;
		void setEval(int);
		bool operator==(const Individual&)const;
		bool operator>(const Individual&)const;
		bool operator<(const Individual&)const;
	private:
		int eval;
};
#endif
