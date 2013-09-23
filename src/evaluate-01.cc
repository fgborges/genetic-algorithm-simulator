#include "src/draw.h"
#include <QDebug>
int Draw::Evaluate()
{
  int eval=100;
  int cnt=0;
  for (auto c : car)
    if (c.get_diff ()==QPointF(0,0))cnt++;
  eval-=(static_cast<qreal>(cnt)/car.size())*100;
  return eval;
}
