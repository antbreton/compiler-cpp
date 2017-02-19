#ifndef _AUTOMATE_H
#define _AUTOMATE_H

#include "Symbole.h"
#include <deque>

class Etat;

class Automate
{
	public :
		// Constructeur normal
		Automate(std::deque<Symbole*>* lexeurSymboleStack);
		
		// Deux opérations de l'automates
		bool decalage(Symbole *s, Etat *e);
		bool reduction(int n, Symbole *s);
		
		// Cette fonction permet de r'ajouter un symbole dans le lexer.
		void push_lexer(Symbole *s);
		Symbole* pop_lexer();
		Symbole* pop_symbol();
		void pop_destroy_symbol();
		
		// Status de l'analyse synthaxique
		bool erreur;
		
		// Fonction qui effectue l'analyse syntaxique
		bool analyse();
		void calculate();
		
		// Affiche la pile d'etats sur cout
		void displayState();
	private :
		std::deque<Symbole*>* symboleStack;
		std::deque<Symbole*>* lexeurSymboleStack;		
		std::deque<Etat*>* stateStack;
		
};

#endif