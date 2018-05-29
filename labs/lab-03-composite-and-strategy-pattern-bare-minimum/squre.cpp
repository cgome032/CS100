// Implementation of squre.h

#include "squre.h"

Sqr::Sqr() : Unary() { };

Sqr::Sqr(Base *single) : Unary(single) { }

double Sqr::evaluate() {
  return this->single->evaluate() * this->single->evaluate();
}
