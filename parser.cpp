#include <iostream>
#include "parser.h"
#include <utility>	// For move()

namespace utils = parser::utility;



// IMPLEMENT PARSE PARAMS AND PARSE BLOCK FUNCTIONS


// Parser functions

AST_Node *parser::wrapperParser(tNode current) {

	// Exit code for recursive Function. (End of Linked List)
	if(!current) return nullptr;

	// Pointer to next AST node
	AST_Node *nextNode = wrapperParser(current->next);

	AST_Node *newNode = parser::parser(current);

	if(!newNode) return nextNode;

	newNode->setNext(nextNode);

	return newNode;

};

AST_Node *parser::parser(tNode node) {

	// Parse Token and return the AST node 
	// the function below produces.

	AST_Node *newNode = nullptr;

	if(*node == token::IS) 
		newNode = parseToken(node);

	return newNode;
};


// Takes in a Token from a Linked List and Parses it.
// Returns an AST Node.
AST_Node *parser::parseToken(tNode current) {
	// Next Token in Linked List.
	tNode next = current->next;
	// Previous Token in Linked List.
	tNode prev = current->prev;



	// Instantiate AST_ID object and return to
	// previous Token in list.
	if(*current == token::IDENTIFIER) {
		// Calls R-Value Constructor to steal Dynamically allocated 
		// data from Token Object since we will no longer need Token.
		return (
			new class AST_ID(AST_ID, std::move(*(current->tokenPtr)))
		);
	}


	// Instantiate AST_BinaryOp object and set values
	// and parse right and left operands.
	if(*current == token::IS) {

		return (
			new AST_BinaryOp(		                         // Pass in previous Token given 
									                        // Linked List's nature of LIFO
				AST_IS, parser::parseOperand(next), parser::parseOperand(prev)
			)
		);
	}


	// Return List or Function

	// Instantiate AST_List Object
	// It's value will be a Linked List 
	// of AST Nodes.
	if(utils::validStartToListOrParams(current)) {

		bool isParams = false;
		tNode startToBlock = nullptr;


		AST_Node *listValue = parser::parseListOrParams(prev, isParams, startToBlock);
		
		AST_Node *list = new AST_List(AST_LIST, listValue);

		if(isParams) {
			return new AST_Function(
				AST_FUNCTION, list, parser::parseBlock(startToBlock->prev)
			);
		}
		else
			return list;

	}


	return nullptr;
};


// Parse operands of an AST operator node
AST_Node *parser::parseOperand(tNode node) {
	return parser::parseToken(node);

};


// Parse List of an AST list node
AST_Node *parser::parseListOrParams(tNode node, bool &isParams, tNode &startToBlock) {

	if(*node == token::BAR) {
		if(utils::validStartToFunctionBlock(node->prev)) {
			isParams = true;
			startToBlock = node->prev->prev;
		}
		return nullptr;	
	} 

	// Recursively Parse each Token in List
	// When closing BAR is reached, nextInList 
	// is set to nullptr.
	AST_Node *nextInList = parser::parseListOrParams(node->prev, isParams, startToBlock);

	// Instantiate an AST object out of  current Token
	// and set its 'next' data member to whatever nextInList
	// is pointing to. Return the AST node.
	AST_Node *newNode = nullptr;

	if(*node == token::COMMA)
		return nextInList;

	if(isParams)
		newNode = parser::parseParams(node);
	else
		newNode = parser::parseList(node);

	newNode->setNext(nextInList);

	return newNode;


};

// Parse List
AST_Node *parser::parseList(tNode node) {
	if(*node == token::IDENTIFIER || *node == token::STRING)
		return parser::parseToken(node);
	else
		//throw error: illegal object in array.
		return nullptr;
}

// Parse parameters
AST_Node *parser::parseParams(tNode node) {
	if(*node == token::IDENTIFIER)
		return parser::parseToken(node);
	else
		//throw error: illegal object in params.
		return nullptr;
};



// Parse statement block
AST_Node *parser::parseBlock(tNode node) {

	// Exit code for recursive Function. (End of Block)
	if(*node == token::BACKTICK) return nullptr;

	AST_Node *newNode = parser::parser(node);

	// Pointer to next AST node
	AST_Node *nextNode = parseBlock(node->prev);

	if(!newNode) return nextNode;

	newNode->setNext(nextNode);


	return newNode;
};



// Utility Functions to help parse Tokens

bool utils::validStartToListOrParams(tNode node) {

	return(*node == token::BAR);
};

bool utils::validStartToFunctionBlock(tNode node) {
	return(
		(*node == token::SKINNY_ARROW) && (*node->prev == token::BACKTICK)
	);
}






