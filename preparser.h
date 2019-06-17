#ifndef PREPARSER_H

#define PREPARSER_H

#include "AST.h"
#include "AST_BinOp.h"
#include "AST_List.h"
#include "AST_Block.h"
#include "AST_STR.h"
#include "AST_ID.h"



// Alias for const token::TokenNode *
typedef const token::TokenNode *tNode;


namespace preparser {

namespace utility {

// UTILITIES 

// Skips to begining of LIST or BLOCK
// tNode skipTo(tNode tn);

}; // utility

// PARSER functions

// MAIN parser function
AST *preparse(tNode tn, tNode exit= nullptr);

// Parses a specific token Node and returns an AST.
astPtr_t parseTNode(tNode tn);

// Parses a LIST from a linked-list of token nodes.
// ASTNode *parseList(tNode tn);
AST *parseList(tNode openingTN);

// Parses a BLOCK from a linked-list of token nodes.
AST *parseBlock(tNode tn);


}; // preparser
#endif