// Implementation of Sub.h

#include "Sub.h"

Sub::Sub() : Operator() { };

Sub::Sub(Base* left, Base* right) : Operator(left, right) { };

double Sub::evaluate() {
  return this->left->evaluate() - this->right->evaluate();
}
