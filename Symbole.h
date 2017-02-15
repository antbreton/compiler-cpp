#ifndef _SYMBOLE_H
#define _SYMBOLE_H
#include <iostream>

class Symbole {

	protected : 
		int ident;
	public :
		Symbole (int id) : ident(id) {}
		virtual ~Symbole() {}
		void print() { cout << (char) ident;}
		operator int () const { return ident; }
};

#endif
