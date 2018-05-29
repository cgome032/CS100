// Implementation of Div.h

#include "Div.h"

Div::Div() : Operator() { };

Div::Div(Base* left, Base* right) : Operator(left, right) { };

double Div::evaluate() {
  return this->left->evaluate() / this->right->evaluate();
};
