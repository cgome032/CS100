#ifndef BASEFACTORY_H
#define BASEFACTORY_H

#include "BasePrint.h"

class BaseFactory {
	public:
		/* Constructor */
		BaseFactory(){}
		
		/* Pure Virtual Generate Function */
		virtual BasePrint* generatePrint(double value) = 0;
};

#endif // BASEFACTORY_H
