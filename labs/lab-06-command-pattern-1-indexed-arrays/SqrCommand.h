#ifndef SQRCOMMAND_H
#define SQRCOMMAND_H

#include "command.h"

class SqrCommand : public Command {
	//SqrCommand Code Here
  public:
    SqrCommand(){}

    SqrCommand(Command* value) {
      root = value->get_root();
    }
 
    double execute() {
      return root->evaluate();
    }

    Base* get_root() {
      return root;
    }

};

#endif // SqrCommand.h
