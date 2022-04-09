#ifndef QUEUE_H_
#define QUEUE_H_

#include"list.h"

// Queue ADT using linked list as primary data structure.
// 
template<typename Type>
class Queue {
public:

	Queue();

	// Basic queue operations
	void	push(Type item);
	void	pop();
	Type	front() const;

	// Check to see if there is anything on the queue
	bool	empty() const;

	// Use to see what is in the queue for debugging
	void	print() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	List<Type> m_list;
};


// Queue Implementation
//

// Queue() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Type>
Queue<Type>::Queue() :m_list() {}

// push():
template<typename Type>
void Queue<Type>::push(Type item) {

	/* TODO */
	m_list.push_rear(item);

}

// pop():
template<typename Type>
void Queue<Type>::pop() {

	/* TODO */
	m_list.pop_front();

}

// empty():
template<typename Type>
bool Queue<Type>::empty() const {

	/* TODO */

	return m_list.empty();
}

// front():
template<typename Type>
Type Queue<Type>::front() const {

	/* TODO */

	Type RETURN_VALUE_REQUIRED_TO_COMPILE; 
	RETURN_VALUE_REQUIRED_TO_COMPILE = m_list.front();
	return RETURN_VALUE_REQUIRED_TO_COMPILE;
}

// print()
template<typename Type>
void Queue<Type>::print() const {

	/* TODO */
	m_list.print();

}




























#endif //QUEUE_H_X_XMMXX 