using namespace std;

// Defines
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"

// Includes persoss
#include "Automate.h"
#include "Etats.h"

// Includes STD
#include <iomanip>      // std::setw




// Constructeur
Automate::Automate(deque<Symbole*>* lexeurSymboleStack):lexeurSymboleStack(lexeurSymboleStack)
{
		symboleStack = new deque<Symbole*>;
		stateStack   = new deque<Etat*>;
		erreur 			 = false;
}

// Deux opérations de l'automates
bool Automate::decalage(Symbole *s, Etat *e)
{
	cout <<setw(40)<<left<< "decalage"<<endl;
	symboleStack->push_back(s);
	stateStack->push_back(e);
	return true;
}

bool Automate::reduction(int n, Symbole *s)
{
	cout <<setw(40)<<left<< "reduction"<<endl;
	for(int i=0;i<n;i++)
	{
		stateStack->pop_back();
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

	stateStack->push_back(new E0); 	// on ajoute l'etat 0

	cout << endl <<'\t'<<setw(40)<<left<< "state" <<setw(40)<<left<<"symbols" <<setw(40)<<left<<"lexer" <<setw(40)<<left<<"rule"<<endl;

	while(!lexeurSymboleStack->empty() && !erreur )		// tant que le lexeur n'est pas vide et qu'il n'y à pas d'erreur
	{			
		displayState();
				
		// On demande à l'état en haut de la pile de considérer
		// ses transitions avec le symbole de haut de pile.
		accepted=(stateStack->back())->transitions(this, pop_lexer()); 
	}
	
	// Affichage des résultats.
	if(erreur)
		cout << endl << endl << RED << "\tError !" << RESET <<endl<<endl;

	if(accepted)
		cout << endl << endl << GREEN << "\tAccepted" << RESET << endl<<endl;
				
	return accepted;
}


void Automate::push_lexer(Symbole *s)
{
	lexeurSymboleStack->push_front(s);
}

Symbole* Automate::pop_symbol()
{
	Symbole * poped =symboleStack->back();	
	symboleStack->pop_back();
	return poped;
}

void Automate::pop_destroy_symbol()
{
	delete(symboleStack->back());
	symboleStack->pop_back();
}

void Automate::calculate()
{
	cout << endl<< GREEN << "\tResult :" << ((Expr *) symboleStack->front())->eval()<<RESET << endl <<endl ;
}		

// Display state of the controller
void Automate::displayState()
{
	deque<Etat*>::iterator it = stateStack->begin();
	cout<<'\t'<<setw(40)<<left;
	
	string states="";
	string symboles="";
	string lexs="";
	
	while (it != stateStack->end())
	{		
		states+= (**it).getName()+" ";
		it++;
	}
	cout << states;
	
	deque<Symbole*>::iterator itt = symboleStack->begin();
	cout<<setw(40)<<left;
	
	while (itt != symboleStack->end())
	{		
		symboles+= (**itt).getPrint()+" ";
		itt++;
	}
	
	cout << symboles;
	
	deque<Symbole*>::iterator ittt = lexeurSymboleStack->begin();
	cout<<setw(40)<<left;
	
	while (ittt != lexeurSymboleStack->end())
	{		
		lexs+=(**ittt).getPrint()+" ";
		ittt++;
	}
	
	cout << lexs;
}

