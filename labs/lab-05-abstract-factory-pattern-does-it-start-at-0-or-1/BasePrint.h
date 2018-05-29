#ifndef BASEPRINT_H
#define BASEPRINT_H

class BasePrint
{
	protected:
	 /*Value to print*/
	 double value;
	public:
	 /*Constructors*/
	 BasePrint(){}
	 BasePrint(double value){}

	 /*Pure Virtual Print Function*/
	 virtual void print() = 0;
};

#endif // BasePrint.h
