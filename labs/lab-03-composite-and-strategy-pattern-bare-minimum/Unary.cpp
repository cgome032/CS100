// Implementation of Unary.h

#include "Unary.h"

Unary::Unary() : Base() { }
Unary::Unary(Base *s) : single(s){}
Base *Unary::get_single() {
  return this->single;
}
