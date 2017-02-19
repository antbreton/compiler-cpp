#ifndef _SYMBOLE_H
#define _SYMBOLE_H
#include <iostream>

class Symbole {

	protected : 
		int ident;
	public :
		Symbole (int id) : ident(id) {}
		virtual ~Symbole() {}
		virtual void print() { std::cout << (char) ident;}
		operator int () const { return ident; }
};

class Nombre : public Symbole {
	protected : 
		int value;
	public :
		Nombre (int valeur) : Symbole((int)'n'), value(valeur) {}
		void print() { std::cout << value;}
};

class Expr : public Symbole {
	public:
		Expr():Symbole('E') {}
		virtual ~Expr() {}	
};

/*
class ExprPlus : public Expr
{

};*/

class ExprParanthese : public Expr
{

};

#endif
