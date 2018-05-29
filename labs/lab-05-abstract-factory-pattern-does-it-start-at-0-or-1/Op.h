#ifndef OP_H
#define OP_H

#include "component.h"

// Leaf Class
class Op: public Base {
 private:
  double value;

 public:
 Op();
 Op(double val);
 double evaluate();

};
#endif // OP_H
