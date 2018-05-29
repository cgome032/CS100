#ifndef DOUBLEFACTORY_H 
#define DOUBLEFACTORY_H 

#include "DoublePrint.h"
#include "BaseFactory.h"

class DoubleFactory : public BaseFactory {
	public:
		/* Constructor */
		DoubleFactory() {}
		
		/* Pure Virtual Generate Function */
		BasePrint* generatePrint(double value) {
		  BasePrint* newDoublePrint = new DoublePrint(value);
		  return newDoublePrint;  	
		}
};

#endif // DOUBLEFACTORY_H
