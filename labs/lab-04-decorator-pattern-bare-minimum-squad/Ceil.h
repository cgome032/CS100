#ifndef CEIL_H
#define CEIL_H

#include <math.h>
#include "Decorator.h"

class Ceil: public Decorator
{
	public:
	Ceil() : Decorator() { };
	Ceil(Base *single) : Decorator(single){}
	double evaluate() 
	{
		return ceil(this->single->evaluate());
	}
};

#endif //CEIL_H

