// Implementation of Op.h

#include "Op.h"

Op::Op() : Base(), value(0) {};

Op::Op(double val) : Base(), value(val) { };

double Op::evaluate() {
  return this->value;
}
