#pragma once
#include "AST.h"
#include "AST_List.h"
#include "AST_ID.h"
#include "AST_BinaryOp.h"
#include "Token.h"


namespace parser {

namespace utility {

	bool validStartToList(token::Token *tokenPtr);

}; // utility



// Parser functions

// Main parser
AST_Node *parser(token::Token *current);


// Takes in a Token from a Linked List and Parses it.
// Returns an AST Node.
AST_Node *parseToken(token::Token *current);

// Parse operands of an AST operator node
AST_Node *parseOperand(token::Token *tokenPtr);


// Parse List of an AST list node
AST_Node *parseList(token::Token *tokenPtr);


}; // parser