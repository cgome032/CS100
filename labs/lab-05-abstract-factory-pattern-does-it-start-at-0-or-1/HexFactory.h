#ifndef HEXFACTORY_H
#define HEXFACTORY_H

#include "BaseFactory.h"
#include "HexPrint.h"

class HexFactory : public BaseFactory {
	public:
		/* Constructor */
		HexFactory(){}

		/* Pure Virtual Generate Function */
		BasePrint* generatePrint(double value){
		  BasePrint* newHexPrint = new HexPrint(value);
		  return newHexPrint;
		}
};

#endif // HEXFACTORY_H
