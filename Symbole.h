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
		virtual std::string getPrint() { std::string res=""; return res+((char) ident);}
		operator int () const { return ident; }
};

class Nombre : public Symbole {
	protected : 
		int value;
	public :
		Nombre (int valeur) : Symbole((int)'n'), value(valeur) {}
		void print() { std::cout << value;}
		int getValue() { return value; }
};

class Expr : public Symbole {
	public:
		Expr():Symbole('E') {}
		virtual ~Expr() {}	
		virtual double eval () = 0;
};


class ExprPlus : public Expr
{
	protected:
		Expr * e1;
		Expr * e2;
		
	public:
		ExprPlus(Expr *e1,Expr *e2): e1(e1), e2(e2) {}
		virtual double eval (){ return e1->eval()+e2->eval(); }
};

class ExprMul : public Expr
{
	protected:
		Expr * e1;
		Expr * e2;
		
	public:
		ExprMul(Expr *e1,Expr *e2): e1(e1), e2(e2) {}
		virtual double eval (){ return e1->eval()*e2->eval(); }
};

class ExprVal : public Expr
{
	protected :
		int val;
	
	public :
		ExprVal(int val):val(val) {}
		virtual double eval (){ return val; }
};

#endif
