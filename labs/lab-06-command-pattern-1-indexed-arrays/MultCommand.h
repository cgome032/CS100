#ifndef MULTCOMMAND_H
#define MULTCOMMAND_H

#include "command.h"

class MultCommand : public Command {
	//MultCommand Code Here
  public:
    MultCommand() {}

    MultCommand(Command* left, double value) {
      Base* right = new Op(value);
      Mult* newRoot = new Mult(left->get_root(),right);
      root = newRoot;
    }

    double execute(){
      return root->evaluate();
    }

    Base* get_root(){
      return root;
    }
};

#endif // MultCommand.h
