#ifndef AST_H

#define AST_H

#include <iostream>
#include <variant>
 

// Forward
class AST_STR; 
class AST_List; 
class AST_ID; 
class AST_Func; 
class AST_Block; 
class AST_BinOp;

/*
 	* To create Linked-List of objects of different types. Why not use their parent since they all share the same
 	* one? The reason is due to some objects having different member variables than their siblings, overloaded 
 	* set_value/get_value methods were needed. I did not want to add all the various methods as virtual methods 
 	* in the Base class.   
*/
typedef std::variant< std::nullptr_t, AST_Str , AST_List , AST_ID , AST_Func , AST_Block , AST_BinOp > ast_t;

/*
	* See AST.cpp
*/
extern bool operator!(const ast_t &astObj);

/*
	* AST_LIST takes in a Macro(N).
	* Each Macro has a signature(type),
	* where type is a unique symbol of 
	* an AST_Node.

	* N: Unique Symbol of each Node in AST
*/

namespace ast {

#define AST_LIST(N) 			    \
	N(ID)							\
	N(ASSIGN)						\
	N(STR)							\
	N(LIST)							\
	N(BLOCK)						\
	N(FUNC)							

// All AST Symbols
#define N(symbol) symbol,
	enum AST_SYMBOL {AST_LIST(N)};
#undef N


}; // ast



struct AST {

	ast_t *node;

	AST *next, *prev;

	AST();
		

	char* getTypeName();

	AST *getValueOfNode();

	/*
		* Overload operator.
	*/
	bool operator==(ast::AST_SYMBOL type);
};

#endif

