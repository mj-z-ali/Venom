#ifndef STACK_H

#define STACK_H

template<typename T>

class Stack {

private:

	Node<T> *head;

public:

	/*
	 +++++++ Main C'tor +++++++++++
	 */

	Stack();

	/*
	 ++++++ Insert ptr to object into stack. +++++++
	 */

	void Stack::push(const SharedPtr<T> &objPtr);

	/*
	 +++++++ Pop object off stack +++++++++++
	 */

	void pop();

	/*
	 +++++++ Pop all objects above given Node in stack +++++++++++
	 */

	void popTop(Node<T> *stackPtr);

	/*
	 +++++ Pop Multiple objects on stack +++++
	 */

	void Stack::popLoop(size_t amount);

	/*
	 +++++ Overloaded subscript operator to access data in linked-list based on index +++++
	 */

	Node<T> &Stack::operator [](size_t indx);

	/*
	 +++++ Returns top of stack without popping it off. Return type is SharedPtr to object of type T +++++++
	 */
	SmartPtr<T> &getTop() const;

}; // Stack

#endif