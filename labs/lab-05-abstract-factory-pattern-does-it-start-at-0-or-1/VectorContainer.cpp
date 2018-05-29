// Implementation of VectorContainer.h

#include "VectorContainer.h"

VectorContainer::VectorContainer(): Container(){}

VectorContainer::VectorContainer(Sort* sort_function) {};

void VectorContainer::add_element(Base* element)
{
  store.push_back(element);
}

void VectorContainer::print()
{
  for (unsigned i = 0; i < store.size(); i++) {
    BasePrint* tempPrint = factory->generatePrint(store[i]->evaluate());
    tempPrint->print();
    //std::cout << ", ";
    //std::cout << store[i]->evaluate() << ", ";
  }
  std::cout << std::endl;
}

void VectorContainer::swap(int i, int j) {
  Base* temp = store.at(i);
  store.at(i) = store.at(j);
  store.at(j) = temp;
}

Base* VectorContainer::at(int i) {
  return store.at(i);
}

int VectorContainer::size(){
  return store.size();
}

void VectorContainer::sort(){
  sort_function->sort(this);
}

void VectorContainer::setFactory(BaseFactory* newFactory){
  factory = newFactory;
}
