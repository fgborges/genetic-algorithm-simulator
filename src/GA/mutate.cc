#include"src/GA/population.h"
#include"src/GA/individual.h"
#include<QVector>
Gene NewGene();
void Population::Mutate(){
  QVector<Individual>::iterator itr;
  QVector<Gene>::iterator itr2;
  for(itr=indiv.begin();itr!=indiv.end();++itr)
    if(qrand()%50==0)
      for(itr2=itr->begin();itr2!=itr->end();++itr2)
    if(qrand()%10)
      *itr2=NewGene();
   return;
}
Gene NewGene()
{
  int key;
  Gene tmp;
  tmp.clear();
  int j;
      key = qrand()%4+2;
      for(j = 0; j<key;j++){
		if(key%2)
			tmp.push_back(true);
		else
			tmp.push_back(false);
	  }
      for(j = 0; j<8-key;j++){
		if(key%2)
			tmp.push_back(false);
		else
			tmp.push_back(true);
      }
	  return tmp;
}
