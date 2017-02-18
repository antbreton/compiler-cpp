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
		
		// Status de l'analyse synthaxique
		bool erreur = false;
		
		// Fonction qui effectue l'analyse syntaxique
		bool analyse();
	private :
		std::deque<Symbole*>* symboleStack;
		std::deque<Symbole*>* lexeurSymboleStack;		
		std::deque<Etat*>* stateStack;
		
};

#endif
