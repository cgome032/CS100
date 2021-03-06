#include <iostream>
#include <vector>
#include "composite.h"
#include "iterator.h"

using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);
    int i = 0;
	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
        cout << "This is the " << i++ << " iteration" << endl;
        pre_itr->current()->print();
        cout << endl;
	}
};
