#include"src/GA/population.h"
#include"src/GA/individual.h"
#include<QVector>
#include<QDebug>
void Population::ClossOver()
{
  QVector<Individual>::iterator indiv1,indiv2;
  QVector<Individual> NewGenelation;
  for(indiv1=indiv.begin();indiv1!=indiv.end();++indiv1){
  for(indiv2=indiv.begin();indiv2!=indiv.end();++indiv2){
    Individual result(0);
    for(int i=0;i<gene_max;i++)
      if(qrand()%2)
        result.push_back(indiv1->at(i));
      else
        result.push_back(indiv2->at(i));
    NewGenelation.push_back(result);
  }}
  indiv.clear();
  for(indiv1=NewGenelation.begin();indiv1!=NewGenelation.end();++indiv1)
    indiv.push_back(*indiv1);
  return;
}
      
