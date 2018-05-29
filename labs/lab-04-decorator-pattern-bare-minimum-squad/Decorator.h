#ifndef DECORATOR_H
#define DECORATOR_H

class Decorator : public Base
{
	protected:
	 Base* single;
	
	public:
	 Decorator() : Base() { }
	 Decorator(Base *s) : single(s){}
	  Base *get_single() { return this->single;}
	  virtual double evaluate() = 0;
};


#endif // DECORATOR_H
