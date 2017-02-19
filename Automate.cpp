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
	cout << "decalage"<<endl;
	symboleStack->push_back(s);
	stateStack->push_back(e);
	return true;
}

bool Automate::reduction(int n, Symbole *s)
{
	cout << "new symb :" ; 
	s->print();
	cout <<endl;
	
	for(int i=0;i<n;i++)
	{
		delete(stateStack->back());
		stateStack->pop_back();
		symboleStack->pop_back();
	}
	lexeurSymboleStack->push_front(s);
	return true;
}


Symbole* Automate::pop_lexer()
{
	Symbole * poped =lexeurSymboleStack->front();	
	lexeurSymboleStack->pop_front();
	return poped;
}
		
		
// Fonction qui effectue l'analyse syntaxique
bool Automate::analyse()
{
	bool accepted = false;

	stateStack->push_back(new E0); 													// on ajoute l'etat 0

	int test;

	while(!lexeurSymboleStack->empty() && !erreur )		// tant que le lexeur n'est pas vide et qu'il n'y à pas d'erreur
	{			
		displayState();
				
		// On demande à l'état en haut de la pile de considérer
		// ses transitions avec le symbole de haut de pile.
		accepted=(stateStack->back())->transitions(this, pop_lexer()); 
		
		cin >> test;
	}
	
	if(erreur)
		cout << "Erreur !" << endl;

	if(accepted)
		cout << "Accepted" << endl;
				
	return true;
}


void Automate::push_lexer(Symbole *s)
{
	lexeurSymboleStack->push_front(s);
}


// Display state of the controller
void Automate::displayState()
{
	deque<Etat*>::iterator it = stateStack->begin();
	cout << "\tstates stack : ";
	
	while (it != stateStack->end())
	{		
		cout << (**it).getName() << " ";
		it++;
	}
	
	deque<Symbole*>::iterator itt = symboleStack->begin();
	cout << endl << "\tsymbole stack : ";
	
	while (itt != symboleStack->end())
	{		
		(**itt).print();
		cout<< " ";
		itt++;
	}
	
	
	deque<Symbole*>::iterator ittt = lexeurSymboleStack->begin();
	cout << endl << "\tlexer : ";
	
	while (ittt != lexeurSymboleStack->end())
	{		
		(**ittt).print();
		cout<< " ";
		ittt++;
	}
	
	cout << endl;
}

