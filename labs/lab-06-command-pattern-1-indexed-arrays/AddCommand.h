#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"

class AddCommand : public Command {
	//AddCommand Code Here
  public:
    AddCommand(){}

    AddCommand(Command* left, double value) {
       Base* right = new Op(value);
       Add* newRoot = new Add(left->get_root(),right);
       root = newRoot; 
    }

    double execute() {
      return root->evaluate();
    }

    Base* get_root(){
      return root;
    }
};

#endif // AddCommand.h
