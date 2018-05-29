#ifndef BINARYPRINT_H
#define BINARYPRINT_H

#include "BasePrint.h"
#include <iostream>
#include <bitset>

class BinaryPrint : public BasePrint {
 protected:
  /* Value to print */
  std::bitset<64> binaryValue;

 public:
  /* Constructors */
  BinaryPrint() : BasePrint() { }
  BinaryPrint(double value) {
	std::bitset<64> newValue(value);
	binaryValue = newValue;
  }

  void print(){
	std::cout << this->binaryValue << std::endl;;
  }

};

#endif // BINARYPRINT_H
