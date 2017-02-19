
// Defines
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"

using namespace std;

#include <iostream>
#include <deque>

#include "lexer.h"
#include "Symbole.h"
#include "Automate.h"


//Prototypes--
void displaySymboles(deque<Symbole*>* q);
// -----------


// Entrypoint of the program, it executes the differents steps : lexer, 
int main(int argv, char ** args)
{
	cout << "Step 0 : Type a line" << endl<<'\t';
	std::string line;
	std::getline (std::cin,line);
  
  cout <<endl<< "Step 1 : lexical analysis" << endl;
	lexer l(line);
	deque<Symbole*>* q = l.lecture();	
	displaySymboles(q);
		
	if(l.getNbError()==0)
		cout << endl << endl << GREEN << "Accepted" << RESET << endl<<endl;
	else
		cout << endl << endl << GREEN << "Accepted" << RESET << " with "<< l.getNbError() <<" error(s)"<< endl<<endl;
						
	cout << "Step 2 : Syntax analysis" << endl;
	Automate automate(q);
	
	if(!automate.analyse()) { return 1; } // On s'arrête s'il y a une erreur
	
	// Sinon on affiche le résultat
	cout << "Step 3 : Result" << endl;
	automate.calculate();
	
	return 0;
}

// This function displays the symbole list
void displaySymboles(deque<Symbole*>* q)
{
	deque<Symbole*>::iterator it = q->begin();
	cout << "\tSymboles stack : ";
	
	while (it != q->end())
	{		
		(**it).print();
		cout<< " ";
		it++;
	}
}
