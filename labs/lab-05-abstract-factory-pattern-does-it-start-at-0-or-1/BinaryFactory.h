#ifndef BINARYFACTORY_H
#define BINARYFACTORY_H

#include "BaseFactory.h"
#include "BinaryPrint.h"

class BinaryFactory : public BaseFactory{
	public:
		BinaryFactory(){}

		BasePrint* generatePrint(double value){
		  BasePrint* newBinaryPrint = new BinaryPrint(value);
		  return newBinaryPrint;
		}



};

#endif

