#ifndef Div_h
#define Div_h

#include "composite.h"

class Div : public Operator
{
	public:
          Div();
          Div(Base* left, Base* right);
          double evaluate();
};
#endif
