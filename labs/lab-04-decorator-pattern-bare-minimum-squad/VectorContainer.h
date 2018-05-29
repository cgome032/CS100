#ifndef VectorContainer_h
#define VectorContainer_h

#include <vector>
#include <iostream>
#include "component.h"
#include "container.h"
#include "strategy.h"
class VectorContainer : public Container
{
	private:
	  std::vector<Base*> store;

	public:
	  /*Constructor*/
	  VectorContainer();
	  VectorContainer(Sort* sort_function);

		void add_element(Base* element);
    void print();
    void swap(int i, int j);
    Base* at(int i);
	  int size();
	  void sort();
};
#endif
