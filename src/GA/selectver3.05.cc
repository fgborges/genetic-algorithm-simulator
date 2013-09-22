/* tournament select */ 
//select.hpp
//ver.3.05 20130919 10:30

//indiv=indivisual置き換え(しなくていい)
//eval=評価 order=順位
#include"src/GA/chromosome.h"
#include"population.h"
#include<algorithm>
#include<QVector>
void Population::Select(){
	int m=0,i=0,n=0;
	int Member[2][IndivNum-LossNum];
	QVector<Individual> result;
	QVector<Individual>::iterator itr;
	std::sort(indiv.begin(),indiv.end());  //＊評価でsort
	for(i=0;i<(IndivNum-LossNum);i++){
		for(n=0;n<2;n++){
			m=qrand()%IndivNum;
			Member[n][i]=m;
		}
	}
//メンバー登録完了
//battle start
	for(i=0;i<IndivNum-LossNum;i++){
		if(indiv.at(Member[0][i]).getEval()>indiv.at(Member[1][i]).getEval())
			result.push_back(indiv.at(Member[0][i]));
		else 
			result.push_back(indiv.at(Member[1][i]));
	}
//	for(i=0;i<IndivNum-LossNum;i++)
//		indiv.at(i)=result.at(i);
	indiv.clear();
	for(itr = result.begin();itr!=result.end();++itr)
		indiv.push_back(*itr);
//	for(i=0;i<LossNum;i++)
//		indiv.pop_back();
}
//やりたいこと
//
//	評価順ソート
//
//ランダムで2個＊(IndivNum-LossNum)だけ抽出　(a[2][Indiv-Loss])
//評価値で比較
//選ばれた奴のナンバーを配列に記憶（b[Indev-Loss]）
//前に持ってくる
//消す
//
//終わり

