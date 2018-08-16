//////////////////
//Hanna Sasina
///////////////////
#include<iostream>
#include <string>

#ifndef LLSTACK_H_
#define LLSTACK_H_

template <class Type>
class LLStack;

///////////////////////////////////////////////////////
//LLNode class
//Represent a Node of a Linked list implemented stack
///////////////////////////////////////////////////////
template <class Type>
class LLNode {

friend class LLStack<Type>;

private:
	Type m_data;
	LLNode<Type>* m_next;

public:
	LLNode(const Type& item);
	virtual ~LLNode<Type>();
};

///////////////////////////////////////////////////////
//LLStack class
//Represents a stack of generic values
//Allows for manipulation of generic values in the stack
////////////////////////////////////////////////////////
template <class Type>
class LLStack {
private:
	// Fields
	LLNode<Type>* topPtr;

public:
	LLStack();
	LLStack(const LLStack&);
	LLStack<Type>& operator=(const LLStack<Type>& rhs);
	virtual ~LLStack<Type>();
	void clear();
	void printStack();
	void push(const Type& newItem);
	void pop();
	Type& top() const throw (std::logic_error);
	bool empty() const;
	int size() const;
};

#endif /* LLSTACK_H_ */
#include "llStack.ipp"


