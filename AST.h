#ifndef AST_H

#define AST_H

#include "AST_Node.h"


struct AST {

	AST_Node *node;

	AST *next, *prev;

	AST()
		:node(nullptr), next(nullptr), prev(nullptr)
	{};
};

#endif


