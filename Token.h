#pragma once


enum Type {
	STRING,
	NUMBER,
	ADDITION,
	SUBTRACTION,
	DIVISION,
	MULTIPLICATION,
	MODULO,
	ASSIGNMENT,
	COMPARISON,
	VARIABLE,
	FUNCTION,
	WRITE,
	ARRAY
};	

class Token {
protected:
	Type type;
	char *name;
	int name_len;
	Token *next;
public:
	Token(char *name, Type type);
	~Token();
	void set_type(Type type);
	Type get_type() const;
	void set_name(char *name);
	char *get_name() const;
	void set_name_len(char *name);
	int get_name_len() const;
	void set_next(Token *tok_ptr);
	Token *get_next() const;

	virtual Token *get_value() const;
	virtual void set_value(Token *tok_ptr);
	
};



