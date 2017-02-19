#ifndef _AUTOMATE_H
#define _AUTOMATE_H

#include "Symbole.h"
#include <deque>

class Etat;

class Automate
{
	public :
		// Regular constructor
		Automate(std::deque<Symbole*>* lexeurSymboleStack);

		// The two operations of the automate
		bool decalage(Symbole *s, Etat *e);
		bool reduction(int n, Symbole *s);

		// This function allow you to add a symbol into the lexer.
		void push_lexer(Symbole *s);
		Symbole* pop_lexer();
		Symbole* pop_symbol();
		void pop_destroy_symbol();

		// Status of the syntactic analysis
		bool erreur;

		// Function who does the syntactic analysis
		bool analyse();
		void calculate();

		// Display the stake of states on cout
		void displayState();
	private :
		std::deque<Symbole*>* symboleStack;
		std::deque<Symbole*>* lexeurSymboleStack;
		std::deque<Etat*>* stateStack;

};

#endif
