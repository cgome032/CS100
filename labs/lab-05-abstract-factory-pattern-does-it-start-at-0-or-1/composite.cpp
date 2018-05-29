// Implementation of composite.cpp

#include "composite.h"

Operator::Operator() : Base(){ };

Operator::Operator(Base* l, Base* r) : left(l), right(r) { }

Base* Operator::get_left() {
  return left;
}

Base* Operator::get_right() {
  return right;
}
