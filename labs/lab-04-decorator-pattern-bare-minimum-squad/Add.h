#ifndef Add_h
#define Add_h

#include "composite.h"

class Add: public Operator
{
 public:
 Add();
 Add(Base* left, Base* right);
 double evaluate();
};
#endif
