#ifndef LISTCONTAINER_H
#define LISTCONTAINER_H

#include <list>
#include <iostream>
#include "container.h"

class ListContainer: public Container{
  private:
    std::list<Base*> store;
    BaseFactory* factory;
  public:
    ListContainer();
    void add_element(Base* element);
    void print();
    void sort();
    void swap(int i, int j);
    Base* at(int i);
    int size();
    void setFactory(BaseFactory* newFactory);
  
};

#endif // LISTCONTAINER_H
