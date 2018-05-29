#ifndef SQURE_H
#define SQURE_H

#include "Unary.h"

class Sqr: public Unary{
 public:

 Sqr();

 Sqr(Base *single);

 double evaluate();

};
#endif // SQURE_H
