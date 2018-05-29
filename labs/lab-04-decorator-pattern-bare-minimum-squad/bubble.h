#ifndef BUBBLE_H
#define BUBBLE_H

#include "strategy.h"
#include "container.h"

class BubbleSort: public Sort{
 public:
  BubbleSort();
  void sort(Container* container);
};

#endif
