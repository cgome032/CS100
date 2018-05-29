#ifndef ABS_H
#define ABS_H

#include "Decorator.h"
#include <math.h>

class Abs: public Decorator
{
	public:
	Abs() : Decorator() {};
	Abs(Base *single) : Decorator(single) {}
	double evaluate()
	{
		return fabs(this->single->evaluate());
	}
};

#endif // ABS_H
