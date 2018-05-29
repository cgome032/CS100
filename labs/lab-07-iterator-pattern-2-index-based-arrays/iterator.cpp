#ifndef ITERATOR_H
#define ITERATOR_H

#include "iterator.h"
// OperatorIterator function definitions

// Initialize current_ptr to the left child
void OperatorIterator::first() {
    current_ptr = self_ptr->get_left();

}

// Moves the iterator to the next child
void OperatorIterator::next() {
    if(current_ptr == self_ptr->get_left()){
        current_ptr = self_ptr->get_right();
    }
    else if(current_ptr == self_ptr->get_right()){
        current_ptr = NULL;
    }
}

// Returns if iterator is at the end
bool OperatorIterator::is_done() {
    if(current_ptr == NULL)
        return true;
    else
        return false;

}

// Returns the current iterator
Base* OperatorIterator::current() {
    return this->current_ptr;
}

// UnaryIterator function definitions

void UnaryIterator::first() {
    this->current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    this->current_ptr = NULL;
}

bool UnaryIterator::is_done() {
    if(current_ptr == NULL)
        return true;
    else
        return false;
}

Base* UnaryIterator::current() {
    return current_ptr;
}

// NullIterator function definitions

// NullIterator first function does nothing
void NullIterator::first() {

}

// NullIterator next function does nothing
void NullIterator::next() {

}

// NullIterator is_done will always return true
bool NullIterator::is_done() {
    return true;
}

// NullIterator current function will always return NULL
Base* NullIterator::current() {
    return NULL;
}

// PreorderIterator function definitions

void PreOrderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    while(!iterators.empty()){
        iterators.pop();
    }
    // The rest of this function needs to be fixed
    Iterator* newPtr = self_ptr->create_iterator();
    newPtr->first();
    iterators.push(newPtr);
}

void PreOrderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
    Iterator* temPtr = iterators.top()->current()->create_iterator();
    temPtr->first();
    iterators.push(temPtr);
    
    if(!iterators.top()->is_done()){
        return; // Do nothing and carry on
    }
    while(iterators.top()->is_done() && iterators.size() >0){
        iterators.pop();
        if(iterators.empty()){
            return;
        }
        iterators.top()->next();
    
    }
}
bool PreOrderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    if(iterators.empty())
        return true;
    else
        return false;
}

Base* PreOrderIterator::current() {
    // Return the current for the top iterator in the stack
    if(!iterators.empty()){
        return (iterators.top())->current();
    }
    else
        return 0;
}

#endif // ITERATOR_H
