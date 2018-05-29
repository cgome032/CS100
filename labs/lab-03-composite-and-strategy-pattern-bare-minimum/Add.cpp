// Implementation of Add Class

#include "Add.h"

Add::Add() : Operator() { };

Add::Add(Base* left, Base* right) : Operator(left, right) {

}

double Add::evaluate() {
  return this->left->evaluate() + this->right->evaluate();
}
