// Implementation of bubble.h

#include "bubble.h"

BubbleSort::BubbleSort(){}

void BubbleSort::sort(Container* container){
  int i,j,flag = 1;
  int numLength = container->size();
  for(i = 1;(i <= numLength) && flag;i++){
    flag = 0;
    for(j = 0;j<(numLength-1);j++){
      if(container->at(j+1)->evaluate() > container->at(j)->evaluate()){
        container->swap(j,j+1);
        flag = 1;
      }
    }
  }
}
