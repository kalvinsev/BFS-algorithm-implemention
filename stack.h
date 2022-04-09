#ifndef STACK_H_
#define STACK_H_

#include"list.h"

// Stack ADT using linked list as primary data structure.
// 
template<typename Type>
class Stack {
public:

	Stack();

	// Basic stack operations
	void	push(Type item);
	void	pop();
	Type	top() const; 

	// Check to see if there is anything on the stack
	bool	empty() const;

	// Use to see what is in the stack for debugging
	void	print() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif

	List<Type> m_list;
};

// Stack Implementation
//

// Stack() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Type>
Stack<Type>::Stack(): m_list() {}

// push():
template<typename Type>
void Stack<Type>::push(Type item) {

	/* TODO */
	m_list.push_rear(item);

}

// pop():
template<typename Type>
void Stack<Type>::pop() {

	/* TODO */
	m_list.pop_rear();

}

// isEmpty():
template<typename Type>
bool Stack<Type>::empty() const {

	/* TODO */

	return m_list.empty();
}

// top():
template<typename Type>
Type Stack<Type>::top() const {

	/* TODO */

	Type RETURN_VALUE_REQUIRED_TO_COMPILE;
	RETURN_VALUE_REQUIRED_TO_COMPILE = m_list.rear();
	return RETURN_VALUE_REQUIRED_TO_COMPILE;
}

// printStack()
template<typename Type>
void Stack<Type>::print() const {

	/* TODO */
	m_list.print();

}




























#endif//STACK_H__X_XMMXX