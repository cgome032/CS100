// Implementation of listcontainer.h

#include "listcontainer.h"

ListContainer::ListContainer(){
}

void ListContainer::add_element(Base* element){
  store.push_back(element);  
}
void ListContainer::print(){
  for(std::list<Base*>::iterator i = store.begin(); i !=store.end(); i++){
    std::cout <<(*i)->evaluate() << " ";
  }
  std::cout << std::endl;
}
void ListContainer::sort(){
  sort_function->sort(this);
}
void ListContainer::swap(int i, int j){
  std::list<Base*>::iterator iter1 = store.begin();
  std::advance(iter1,i);

  std::list<Base*>::iterator iter2 = store.begin();
  std::advance(iter2,j);

  std::swap(*iter1,*iter2);
}
Base* ListContainer::at(int i){
  std::list<Base*>::iterator iter = store.begin();
  std::advance(iter,i);
  return *iter;
}
int ListContainer::size(){
  return store.size();
}
