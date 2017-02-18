using namespace std;

#include "Automate.h"
#include "Etats.h"

// Constructeur
Automate::Automate(deque<Symbole*>* lexeurSymboleStack):lexeurSymboleStack(lexeurSymboleStack)
{
		symboleStack = new deque<Symbole*>;
		stateStack   = new deque<Etat*>;
}

// Deux opérations de l'automates
bool Automate::decalage(Symbole *s, Etat *e)
{
	return true;
}

bool Automate::reduction(int n, Symbole *s)
{
	return true;
}

// Fonction qui effectue l'analyse syntaxique
bool Automate::analyse()
{
	cout << "\t begining..." << endl;
	
	stateStack->push_back(new E0); 													// on ajoute l'etat 0
	symboleStack->push_back(lexeurSymboleStack->back()); 		// et on récupère le premier symbole du lexer
	lexeurSymboleStack->pop_back();
	
	while( (*lexeurSymboleStack->front() == ((int) '$') )						// Tant qu'on a pas atteind le $ dans la pile 
	|| !erreur )																									// ou qu'il n'y à pas d'erreur
	{	
		cout << "\t Current Symbole...";
		 (lexeurSymboleStack->front())->print();
		cout << endl;
		// On demande à l'état en haut de la pile de 
		// considérer ses transitions avec le symbole de haut de pile.
		(stateStack->back())->transitions(this, symboleStack->back()); 
		stateStack->pop_back();
		symboleStack->pop_back();
	}
	
	if(erreur)
		cout << "Erreur !" << endl;
		
	return true;
}
