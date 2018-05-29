#include <iostream>
#include "composite.h"
#include "strategy.h"
#include "Op.h"
#include "Div.h"
#include "Mult.h"
#include "Sub.h"
#include "Add.h"
#include "squre.h"
#include "VectorContainer.h"
#include "listcontainer.h" 
#include "selection.h"
#include "bubble.h"

using namespace std;

int main() {
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    Op* op3 = new Op(3);
    Op* op2 = new Op(2);
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, A);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);

    VectorContainer* Vectcontainer = new VectorContainer();
    ListContainer* Licontainer = new ListContainer();
    
    // Testing Vector Container
    Vectcontainer->add_element(A);
    Vectcontainer->add_element(B);
    Vectcontainer->add_element(C);
    Vectcontainer->add_element(D);

    cout << "Container Before Sort: " << endl;
    Vectcontainer->print();
    cout << endl;
    
    cout << "Container After Sort: " << endl;
    Vectcontainer->set_sort_function(new BubbleSort());
    Vectcontainer->sort();	
    Vectcontainer->print();
    cout << endl;

    // Testing List Container
    Licontainer->add_element(A);
    Licontainer->add_element(B);
    Licontainer->add_element(C);
    Licontainer->add_element(D);

    cout << "Container Before Sort: " << endl;
    Licontainer->print();
    cout << endl;
    
    cout << "Container After Sort: " << endl;
    Licontainer->set_sort_function(new SelectionSort());
    Licontainer->sort();	
    Licontainer->print();
    cout << endl;
};
