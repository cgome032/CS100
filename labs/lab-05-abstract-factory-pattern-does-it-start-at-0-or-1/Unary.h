#ifndef UNARY_H
#define UNARY_H

#include "component.h"

class Unary: public Base{
protected:
  Base *single;
public:
  Unary();
  Unary(Base *s);
  Base *get_single();
  
  virtual double evaluate() = 0;
};

#endif // UNARY_H
