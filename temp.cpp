#include <iostream>
#include "Dimension.h"
#include "Token.h"



int main() {

	Dimension *d = Dimension::getInstance();

	Dimension *c = Dimension::getInstance();


	token::TokenNode *tn = new token::TokenNode;

	token::TokenNode *tn2 = new token::TokenNode;

	token::TokenNode *tn3 = new token::TokenNode;

	token::TokenNode *tn4 = new token::TokenNode;

	token::TokenNode *tn5 = new token::TokenNode;

	token::TokenNode *tn6 = new token::TokenNode;

	d->insertOpen(tn);

	d->insertOpen(tn2);

	d->insertOpen(tn3);

	d->insertOpen(tn4);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertOpen(tn5);

	d->insertClose(tn6);


	unsigned i;

	*d>>i;

	if(*d == 8)
		std::cout << "It's 8" << std::endl;
	else if(*d < 8)
		std::cout << "Less than 8" << std::endl;

	else if(*d <= 10)
		std::cout << "Less than eq to 10" << std::endl;

	else if(*d > 12)
		std::cout << "Greater than 11" << std::endl;

	else if(*d >= 11)
		std::cout << "Greater than eq to 11" << std::endl;


	std::cout << i << std::endl;

};



