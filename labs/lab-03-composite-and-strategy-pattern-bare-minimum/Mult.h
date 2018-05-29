#ifndef Mult_h
#define Mult_h

#include "composite.h"

class Mult: public Operator
{
 public:
 Mult();

 Mult(Base* left, Base* right);

 double evaluate();
};
#endif
