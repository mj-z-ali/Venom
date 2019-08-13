
#ifndef STR_H

#define STR_H


#include <string>
#include "ast_t.h"
#include "../lexer/token/Token.h"




class Str {

private:

	std::string value;

public:

	/*
	 +++++ MAIN C'TOR +++++
	 */
	
	/*
	 +++++ C'Tor for moving std::string value from token to Str +++++
	 */

	Str(Token &&token);

	/*
	 +++++ Moves for calling std::string move C'tor +++++
	 */
	/*
	 +++++ MOVE C'TOR +++++
	 */
	Str(Str&& strObj);

	/*
	 +++++ MOVE ASSIGN +++++
	 */
	Str& operator=(Str&& strObj);


}; // Str

#endif