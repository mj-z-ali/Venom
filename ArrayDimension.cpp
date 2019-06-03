#include "Dimension.h"
#include "ArrayDimension.h"
#include "Token.h"


/*
	Each instance of this class will contain a Token Node
	that either is an opening to a new dimension or closing
	of an existing one. Each instance will be chained together 
	in a Linked-List.
*/


/* TEMP
struct ArrayDimension::Node {

	const token::TokenNode *tn;

	Node *next, *prev;
	Node() 
		:tn(nullptr), next(nullptr), prev(nullptr)
	{std::cout << "Node Was Created!" << std::endl;}

*/
	/* 
		Destructor: Deletes Chain.
		Do not delete tn, as tn is pointer to TokenNode
		that is in use by other components.
	*/

	/*TEMP
	~Node() {
		if(next) delete next;
		std::cout << "Node Was Deleted!" << std::endl;
		next = nullptr, prev = nullptr, tn = nullptr;
	}
};


*/


/*
 	Each instance of this class will contain a Linked-List
	of Tokens that are either Opening or Closing a dimension 
	to a block or array. Each one of these instances will in 
	of itself be chained in a linked list with the purpose of
	representing separate arrays or blocks.
*/

/*TEMP
struct ArrayDimension::NodeOfNodes {
	// Linked-List of Openings and 
	// Closings To ArrayDimension.
	Node *opening,  *closing,  // Head Pointers.
		 *openingT, *closingT; // Tail pointers.

	NodeOfNodes *next, *prev;

	NodeOfNodes()
		:
			opening(nullptr), closing(nullptr), openingT(nullptr),
			closingT(nullptr), next(nullptr), prev(nullptr)
	{std::cout << "NodeOfNodes Was Created!" << std::endl;};


	~NodeOfNodes() {
		std::cout << "NodeOfNodes Was Deleted!" << std::endl;
		// Delete Linked-List of Nodes.
		if(opening) delete opening;
		if(closing) delete closing;

		// Delete chain of objects of NodeOfNodes Type.
		if(next) delete next;

		opening = nullptr, closing = nullptr,
		openingT = nullptr, closingT = nullptr,
		next = nullptr, prev = nullptr;
	}
};

*/

// Deletes Linked-List properties.
ArrayDimension::~ArrayDimension() {
	std::cout << "ArrayDimension Was Deleted!" << std::endl;

	// Delete Linked-List of NodeOfNodes.
	if(head) delete head;
	head = nullptr, tail = nullptr;
};

// Insert Opening to a new ArrayDimension into a Linked-List.
void ArrayDimension::insertOpen(const token::TokenNode *tn) {

	if(D == 0) { // New Block or Array

		NodeOfNodes *newNodeOfNodes = new NodeOfNodes(); 

		// Insert newNodeOfNodes into Linked-List.
		// Start...

		newNodeOfNodes->next = head; 

		// Set neighbor prev (if exist) to point to newNodeOfNodes node.
		if(head) newNodeOfNodes->next->prev = newNodeOfNodes;
		else tail = newNodeOfNodes; // It's the first (will be last) one, so set Tail.

		head = newNodeOfNodes; // Set Head.

		// Finish
	}


	Node *newOpen = new Node();

	
	// Insert newOpen into Linked-List.
	// Start...

	newOpen->tn = tn;

	newOpen->next = head->opening;

	// Set neighbor prev (if exist) to point to newOpen node.
	if(head->opening) newOpen->next->prev = newOpen;
	else head->openingT = newOpen; // It's the first (will be last) one, so set Tail.

	head->opening = newOpen; // Set Head

	// Finish.

	D++; // Increment Dimension

};

// Insert Closing to a new ArrayDimension into a Linked-List.
void ArrayDimension::insertClose(const token::TokenNode *tn) {

	// TODO. Throw error if head DNE.

	Node *newClose = new Node();

	
	// Insert newClose into Linked-List.
	// Start...

	newClose->tn = tn;

	newClose->next = head->closing;

	// Set neighbor prev (if exist) to point to newClose node.
	if(head->closing) newClose->next->prev = newClose;
	else head->closingT = newClose; // It's the first (will be last) one, so set Tail.

	head->closing = newClose; // Set Head

	// if(D <= 0) throw error

	// Finish.

	D--; // Decrement Dimension

};


// Overload operators

/*TEMP

bool ArrayDimension::operator==(int i)  const {
	return (D == i);
};

bool ArrayDimension::operator<=(int i)  const {
	return (D <= i);
};

bool ArrayDimension::operator>=(int i)  const {
	return (D >= i);
};

bool ArrayDimension::operator<(int i)   const {
	return (D < i);
};

bool ArrayDimension::operator>(int i)   const {
	return (D > i);
};

unsigned ArrayDimension::operator>>(unsigned &i)  const {
	i = D;

	return i;
};

*/



