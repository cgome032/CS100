#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"

class Operator: public Base {
 protected:
  Base *left, *right;
 public:

 Operator();
 Operator(Base* l, Base* r);

  Base* get_left();
  Base* get_right();
  virtual double evaluate() = 0;
};

#endif // COMPOSITE_H
