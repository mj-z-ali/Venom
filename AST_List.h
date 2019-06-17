#ifndef AST_LIST_H

#define AST_LIST_H

#include "AST_Node.h"



class AST_List : AST_Node {

private:

	AST *value;


public:

	AST_List(ast::AST_SYMBOL type, AST *value);

	void setValue(AST *value);


}; // AST_List



#endif