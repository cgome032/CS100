#ifndef OPCOMMAND_H
#define OPCOMMAND_H

#include "command.h"
 
class OpCommand : public Command {
	//OpCommand Code Here
  public:
   OpCommand(){}
   
   // Not sure if this is how constructor should look like
   OpCommand(double value) {
    Base* newValue = new Op(value); 
    root = newValue;
   }

   double execute() {
    return root->evaluate();
   }

   Base* get_root() {
    return root;
   }
};

#endif // OpCommand.h
