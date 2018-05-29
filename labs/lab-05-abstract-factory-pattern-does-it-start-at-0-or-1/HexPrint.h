#ifndef HEXPRINT_H
#define HEXPRINT_H

#include "BasePrint.h"
#include <iostream>

class HexPrint : public BasePrint {
	protected:
	 /*Value to print*/
	 double value;
	public:
	 /*Constructors*/
	 HexPrint() : BasePrint(){}
	 HexPrint(double value){}

	 /*Pure Virtual Print Function*/
	 void print() {
		 std::cout.precision(4);
	   std::cout << std::hexfloat;
	   std::cout << value << std::endl;
	 }
};

#endif // HEXPRINT_H
