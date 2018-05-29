#include <iostream>
#include "composite.h"
#include "strategy.h"
#include "Op.h"
#include "Div.h"
#include "Mult.h"
#include "Sub.h"
#include "Add.h"
#include "squre.h"
#include "Floor.h"
#include "Ceil.h"
#include "Abs.h"
#include "VectorContainer.h"
#include "listcontainer.h"
#include "selection.h"
#include "bubble.h"
#include "DoubleFactory.h"
#include "HexFactory.h"
#include "BinaryFactory.h"
using namespace std;

int main(int argc, char *argv[]) {
    Op* op7 = new Op(-7);
    Op* op4 = new Op(4.2);
    Op* op3 = new Op(1.3);
    Op* op2 = new Op(2);
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, A);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);
    DoubleFactory* dubFactory = new DoubleFactory();
    HexFactory* hexFactory = new HexFactory();
    BinaryFactory* binFactory = new BinaryFactory();
    if(argc == 2)
      cout << "Your first argument was: " << *argv[1] << endl;
    else
      cout << "No first argument was present" << endl;
    VectorContainer* container1 = new VectorContainer();
    ListContainer* container2 = new ListContainer();
    if(argc == 2){
      char option = *argv[1];
      switch(option){
        case 'd':
        {
        container1->setFactory(dubFactory);
        container2->setFactory(dubFactory);
        }
        break;

        case 'h':
        {
        container1->setFactory(hexFactory);
        container2->setFactory(hexFactory);
        }
        break;

        case 'b':
        {
        container1->setFactory(binFactory);
        container2->setFactory(binFactory);
        }
        break;

        default:
        {
        std::cout << "That is an invalid option" << std::endl;
        }
        break;
      }

     cout << "Testing Vector Container functionality: " << endl;
     cout << "Adding regular elements into Vector: " << endl;
     container1->add_element(A);
     cout << "Added element A" << endl;
     container1->add_element(B);
     cout << "Added element B" << endl;
     container1->add_element(C);
     cout << "Added element C" << endl;
     container1->add_element(D);
     cout << "Added element D" << endl;
     container1->print();

     cout << "Ceil'ing 4th element and adding result to container" << endl;
     Ceil* E = new Ceil(D);
     container1->add_element(E);
     container1->print();

     cout << "Floor'ing 4th element and adding result to container" << endl;
     Floor* F = new Floor(D);
     container1->add_element(F);
     container1->print();

     cout << "Abs'ing 2nd element and adding result to container" << endl;
     Abs* G = new Abs(B);
     container1->add_element(G);
     container1->print();

     cout << "Flooring the most recent Abs'ed element and adding result to container" << endl;
     Floor* H = new Floor(G);
     container1->add_element(H);
     container1->print();

     cout << "Sorting the Vector" << endl;
     cout << "Container Before Sort: " << endl;
     container1->print();

     cout << "Container After Selection Sort: " << endl;
     container1->set_sort_function(new SelectionSort());
     container1->sort();
     container1->print();

     cout << "Container after Bubble Sort: " << endl;
     container1->set_sort_function(new BubbleSort());
     container1->sort();
     container1->print();

     cout << "Testing List Container functionality: " << endl;
     cout << "Adding regular elements into List: " << endl;
     container2->add_element(A);
     container2->add_element(B);
     container2->add_element(C);
     container2->add_element(D);
     container2->print();

     cout << "Ceil'ing 4th element and adding result to container" << endl;
     Ceil* I = new Ceil(D);
     container2->add_element(I);
     container2->print();

     cout << "Floor'ing 4th element and adding result to container" << endl;
     Floor* J = new Floor(D);
     container2->add_element(J);
     container2->print();

     cout << "Abs'ing 2nd element and adding result to container" << endl;
     Abs* K = new Abs(B);
     container2->add_element(K);
     container2->print();

     cout << "Flooring the most recent Abs'ed element and adding result to container" << endl;
     Floor* L = new Floor(G);
     container2->add_element(L);
     container2->print();

     cout << "Sorting the List" << endl;
     cout << "Container Before Sort: " << endl;
     container2->print();

     cout << "Container After Selection Sort: " << endl;
     container2->set_sort_function(new SelectionSort());
     container2->sort();
     container2->print();

     cout << "Container after Bubble Sort: " << endl;
     container2->set_sort_function(new BubbleSort());
     container2->sort();
     container2->print();
 }
 else{
   cout << "No argument flag was present" << endl;
 }
};
