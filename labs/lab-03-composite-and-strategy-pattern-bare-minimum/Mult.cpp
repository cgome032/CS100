// Implementation of Mult.h

#include "Mult.h"

Mult::Mult() : Operator() { };

Mult::Mult(Base* left, Base* right) : Operator(left, right) { };

double Mult::evaluate() {
  return this->left->evaluate() * this->right->evaluate();
}
