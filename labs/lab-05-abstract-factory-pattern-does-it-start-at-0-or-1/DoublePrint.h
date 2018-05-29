#ifndef DOUBLEPRINT_H
#define DOUBLEPRINT_H

#include <iostream>
#include "BasePrint.h"

class DoublePrint : public BasePrint
{
	protected:
         double doubleVal;

	public:
	 DoublePrint() : BasePrint(){ }
  	 DoublePrint(double value)
	 {
	    double newVal(value);
	    doubleVal = newVal;
	 }

	 void print()
	 {
	    std::cout << this->doubleVal << std::endl;;
	 }
};

#endif // DoublePrint.h
