//////////////////
//Hanna Sasina
///////////////////

#ifndef LLSTACK_IPP_
#define LLSTACK_IPP_

#include<iostream>
#include <string>

using namespace std;

template<class Type>
// constructor for LLNode
LLNode<Type>::LLNode(const Type& item) : m_data(item), m_next(nullptr) {
}

//destructor for LLNode
template<class Type>
LLNode<Type>::~LLNode() {
}

//////////////////////////////////////////////////////////////////
//Construtors - Copy constructors - Destructors for LLStack
////////////////////////////////////////////////////////////////
template<class Type>
LLStack<Type>::LLStack() : topPtr(nullptr) {
}

// copy Constructor
template<class Type>
LLStack<Type>::LLStack(const LLStack& stack) : topPtr(nullptr) {
	*this = stack;
}

template<class Type>
LLStack<Type>& LLStack<Type>::operator=(const LLStack<Type>& rhs) {
	// check for self-assignment first
	if (this != &rhs) {
		if (rhs.topPtr == nullptr) {
			topPtr = nullptr;
		}
		else {
			// delete already existing nodes in this and only then copy
			// to avoid memory leak
			clear();
			LLNode<Type>* cur1 = nullptr;
			LLNode<Type>* cur2 = nullptr;

			topPtr = new LLNode<Type>(rhs.topPtr->m_data);
			cur1 = topPtr;
			cur2 = rhs.topPtr->m_next;
			while (cur2 != nullptr) {
				cur1->m_next = new LLNode<Type>(cur2->m_data);
				cur1 = cur1->m_next;
				cur2 = cur2->m_next;
			}
			cur1->m_next = nullptr;
		}
	}
	return *this;
}

// destructor for LLStack
template<class Type>
LLStack<Type>::~LLStack() {
	clear();
}

// clear method to remove everything from the stack
template<class Type>
void LLStack<Type> :: clear() {
	while (!empty()) {
		pop();
	}
}

// print Stack to the console for testing
template<class Type>
void LLStack<Type>::printStack() {
	LLNode<Type>* current = topPtr;
	cout << "Stack: " << endl;
	while (current != nullptr) {
		cout << current->m_data;
		cout << " ";
		current = current->m_next;
	}
}

// push items on the stack
template<class Type>
void LLStack<Type>::push(const Type& newItem) {
	// If stack is empty
	if (topPtr == nullptr) {
		topPtr = new LLNode<Type>(newItem);
	}
	// if not empty
	else {
		LLNode<Type>* insert = new LLNode<Type>(newItem);
		insert->m_next = topPtr;
		topPtr = insert;
	}
}

// remove last element
// 3 cases: 1. front is null 2. stack has only one node 3. stack has multiple nodes
template<class Type>
void LLStack<Type>::pop() {
	// 1. Front is null
	if (topPtr == nullptr) {
		return;
	}
	//2. Stack has only one node
	if (topPtr->m_next == nullptr) {
		delete (topPtr);
		topPtr = nullptr;
	}
	else {
		//3. Stack has multiple nodes
		LLNode<Type>* toDelete = topPtr;
		topPtr = topPtr->m_next;
		delete (toDelete);
		toDelete = nullptr;
	}
}

// look at the top element and return it
// trow logic error if there is nothing at the top
template<class Type>
Type& LLStack<Type>::top() const throw (logic_error) {
	if (topPtr == nullptr) {
		throw logic_error("Stack is empty");
	}
	else {
		return topPtr->m_data;
	}
}

// check if array is empty
template<class Type>
bool LLStack<Type>::empty() const {
	return topPtr == nullptr;
}

// check stack's size
template<class Type>
int LLStack<Type>::size() const {
	int size = 0;
	LLNode<Type>* current = topPtr;
	while (current != nullptr) {
		current = current->m_next;
		size++;
	}
	return size;
}

#endif /* LLSTACK_IPP_ */

