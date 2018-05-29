#ifndef SELECTION_H
#define SELECTION_H

#include "strategy.h"
#include "container.h"

class SelectionSort: public Sort{
 public:
  SelectionSort();
  void sort(Container* container);
};










#endif
