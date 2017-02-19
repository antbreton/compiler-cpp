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
	symboleStack->push_back(s);
	stateStack->push_back(e);
	return true;
}

bool Automate::reduction(int n, Symbole *s)
{
	for(int i=0;i++; i<n)
	{
		delete(stateStack->back());
		stateStack->pop_back();
	}
	
	lexeurSymboleStack->push_front(s);
	return true;
}

// Fonction qui effectue l'analyse syntaxique
bool Automate::analyse()
{
	bool accepted = false;
	cout << "\t begining..." << endl;
	string fuck;
	stateStack->push_back(new E0); 													// on ajoute l'etat 0
	symboleStack->push_back(lexeurSymboleStack->back()); 		// et on récupère le premier symbole du lexer
	lexeurSymboleStack->pop_back();
	
	while( !lexeurSymboleStack->empty() 										// Tant que la pile n'est pas vide
	|| !erreur )																						// ou qu'il n'y à pas d'erreur
	{	
		cout << "\t Current Symbole... ";
		 (lexeurSymboleStack->front())->print();
		cout << endl;
		
		cout << "\t s: " << stateStack->back()->getName() << endl;
		
		// On demande à l'état en haut de la pile de 
		// considérer ses transitions avec le symbole de haut de pile.
		accepted=(stateStack->back())->transitions(this, lexeurSymboleStack->front()); 
		lexeurSymboleStack->pop_front();
	//	cin >> fuck;
	}
	/*
	if(erreur)
		cout << "Erreur !" << endl;

	if(accepted)
		cout << "Accepted" << endl;
				*/
	return true;
}
