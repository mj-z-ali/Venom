#include "ID.h"


/*
 +++++ MAIN C'TOR +++++
 */
/*
 +++++ C'Tor for moving std::string value from token to ID +++++
 */
ID::ID(Token &&token)	
	:value(std::move(token.getValue()))
{}


/*
 +++++ Moves for calling std::string move C'tor +++++
 */
/*
 +++++ MOVE C'TOR +++++
 */
ID::ID(ID&& idObj)
	:value(std::move(idObj.value))
{}


/*
 +++++ MOVE ASSIGN +++++
 */
ID& ID::operator=(ID&& idObj) {
	value = std::move(idObj.value);
}