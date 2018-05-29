#ifndef FLOOR_H
#define FLOOR_H

#include "Decorator.h"
#include <math.h>

class Floor: public Decorator 
{
	public:
	Floor() : Decorator() {};
	Floor(Base *single) : Decorator(single) {}
	 double evaluate() 
	   {
		return floor(this->single->evaluate());
	   }
};

#endif //  FLOOR_H
