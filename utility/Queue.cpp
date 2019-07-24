#include "Queue.h"
#include "Node.h"

Queue::Queue()
	:head(nullptr), tail(nullptr), _current(nullptr)
{};


/*
	*
	* Pushes an object at the end of the Queue.
	* Params: variable number of arguments that
	* will be passed into T object constructor. 
	* Creates T object emplace.
	*
*/
template<typename ... Params>

void Queue::enqueue(Params&& ... params) {

	Node<T> *newNode = new Node<T>;

	/*
		*
		* Forward L-Value or R-Value when passing to T constructor.
		*
	*/
	newNode->value = new T(std::forward<Params>(params)...);

	/*
		*
		* First Node in Queue. Assign all pointers to it.
		*
	*/
	if(!head) {head = newNode; tail = newNode; _current = newNode;}

	/*
		*
		* Append Node to Queue.
		*
	*/
	else {

		tail->next = newNode;

		newNode->prev = tail;

		tail = newNode;
	}

};


/*
	*
	* Moves "_current" pointer a number of places ahead.
	* Params: Number of places to move in the Queue.
	*
*/
void Queue::jump(unsigned places) {

	for(unsigned i = 0; _current && i < places; ++i, _current = _current->next);
};


/*
	*
	* Returns Node in Queue that "_current" is pointing to.
	*
*/
Node<T> *Queue::current() {
	return _current;
};


/*
	*
	* Returns object of type T that the last Node in Queue holds.
	*	
*/
T *Queue::end() {

	return tail->value
};