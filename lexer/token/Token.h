#ifndef TOKEN_H

#define TOKEN_H




/*
 +++++ TOKEN_LIST takes in a Token Macro (T). Each Macro has the same +++++
 +++++ signature M(type, name), where type is a unique symbol for the +++++
 +++++ Token and nameis a string containing the Token. T: Token macro +++++
 */
 
#define TOKEN_LIST(T)							    \
	T(IS, "is")									    \
	T(IF, "if")										\
	T(EQ, "=")										\
	T(BAR, "|")										\
	T(TAB, "\t")									\
	T(EQEQ, "==")									\
	T(ELSE, "else")									\
	T(ELIF, "elif")									\
	T(COMMA, ",")									\
	T(ARROW, "->")									\
	T(STRING, nullptr)								\
	T(OUTPUT, "output")								\
	T(NEWLINE, "\n")								\
	T(LBRACKET, "[")								\
	T(RBRACKET, "]")								\
	T(LHANDLE, ":|")								\
	T(RHANDLE, "|:")								\
	T(BACKTICK, "`")								\
	T(IDENTIFIER, nullptr)						    
								



class Token {

public:


	/*
		*
		* All Token Symbols
		*
	*/
#define T(symbol, name) symbol,
	/* 
		* In this case, only the symbol is needed
		* and the second parameter is unused to
		* generate the List of Token Symbols.
	*/
	enum Symbol{TOKEN_LIST(T) NUM_OF_TOKENS};

#undef T


	/*
		*
		* Used to map strings to their corresponding
		* Symbol in O(1) time complexity.
		*
	*/
	static SharedPtr< Trie<Symbol> > mapToSymbol;

	/*
		*
		* All Token symbols in string form for logging.
		*
	*/
	static std::vector<std::string> typeName;

	

	/*
		----------------
		  Constructors
		----------------
	*/

	/*
		*
		* IDENTIFIER and STRING Constructor.
		*
	*/
	Token(const std::string &stream, Symbol symType);

	/*
		*
		* Constructor for Everything else like keywords, operators, etc,
		*
	*/
	Token(Symbol symType);


	/*
		------------------
		  Getter methods
		------------------

	*/


	/*
		*
		* Gets the Token's symbol type in string form.
		*
	*/
	static const std::string &getTypeName();

	/*
		*
		* Does this Token close off an array, block, or parameter list?
		*
	*/
	bool isClosing() const;

	SharedPtr<Token> &getMatchingPair() const;


	/*
		------------------
		  Setter methods
		------------------

	*/

	void setClosing(bool isClosing);


	void setMatchingPair(SharedPtr<Token> &matchingPair);


	/*
		------------------------
		  Overloaded Operators
		------------------------

	*/

	/*
		*
		* Overload operator to compare by symbol type.
		*
	*/
	bool operator==(Symbol typeToCompare) const;


private:

	/*
		*
		* This data member is set to nullptr unless type is a STRING or IDENTIFIER.
		*
	*/
	std::string value;

	/*
		*
		* Indicates that this Token is an end to a block, array, or parameter list.
		*
	*/
	bool closing;

	/*
		*
		* The matching opening/closing Token if this Token opens/closes an
		* array, block, or parameter list. Otherwise, set to nullptr.
		*
	*/
	SharedPtr<Token> matchingPair;


	Symbol type; 

}; // Token


#endif





