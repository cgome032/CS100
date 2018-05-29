#ifndef Sub_h
#define Sub_h

#include "composite.h"

class Sub: public Operator
{
       public:
         Sub();
         Sub(Base* left, Base* right);
         double evaluate();
};
#endif
