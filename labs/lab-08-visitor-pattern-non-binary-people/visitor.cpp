#include "visitor.h"
#include <iostream>
#include <sstream>

PrintVisitor::PrintVisitor() {
    output = "";
}

void PrintVisitor::rootNode(){		//For visiting a root node (do nothing)

}
void PrintVisitor::sqrNode(){    //For visiting a square node
    output += "^ ";
}
void PrintVisitor::multNode(){		//For visiting a multiple node
    output += "* ";
}
void PrintVisitor::subNode(){		//For visiting a subtraction node
    output += "- ";
}
void PrintVisitor::addNode(){		//For visiting an add node
    output += "+ ";
}
void PrintVisitor::opNode(Op* op){	//For visiting a leaf node
    std::ostringstream strs;
    strs << (op->evaluate());
    std::string str = strs.str();
    output += str;
    output += " ";
    
}
void PrintVisitor::execute(){		//Prints all visited nodes
    std::cout << output << std::endl;
}
