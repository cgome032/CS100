#ifndef SUBCOMMAND_H
#define SUBCOMMAND_H 

#include "command.h"

class SubCommand : public Command {
	//SubCommand Code Here
  public:
    SubCommand() {}
 
    SubCommand(Command*left, double value){
      Base* right = new Op(value);
      Sub* newRoot = new Sub(left->get_root(),right);
      root = newRoot;
    }

    double execute() {
      return root->evaluate();
    }

    Base* get_root(){
      return root;
    }
};


#endif // SubCommand.h
