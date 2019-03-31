#include "lexer.h"








void lexer(char *file_name) {
	char data;
	ifstream in_file;
	in_file.open(file_name);

	
	while(in_file >> data) {
		

		if(data == '{') {
			tk *new_tok = new tk;
			new_tok->TYPE  = "RBRACE";
			new_tok->VALUE = '{';
			new_tok->NEXT  = head;
			head           = new_tok;
		}
		else if(data == 'a') {
			tk *new_tok = new tk;
			new_tok->TYPE  = "CHAR";
			new_tok->VALUE = 'a';
			new_tok->NEXT  = head;
			head           = new_tok;
		}
	}
	in_file.close();

	cout << head << endl;

}