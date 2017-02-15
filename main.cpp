// TODO DISPLAY DEQUE BY MODIFING THE PRINTS METHODS
using namespace std;
#include "lexer.h"
#include <iostream>
#include <deque>
#include "Symbole.h"

//Prototypes--
void displaySymboles(deque<Symbole*> q);
// -----------

// Entrypoint of the program, it executes the differents steps : lexer, 
int main(int argv, char ** args)
{
	cout << "Type a line" << endl;
	std::string line;
	std::getline (std::cin,line);
  
  cout << "Step 1 : lexical analysis" << endl;
	lexer l(line);
	deque<Symbole*> q = l.lecture();	
	displaySymboles(q);

	
	cout << endl;
	return 0;
}

// This function displays the symbole list
void displaySymboles(deque<Symbole*> q)
{
	deque<Symbole*>::iterator it = q.begin();
	cout << "\tSymboles stack : ";
	
	while (it != q.end())
	{		
		(**it).print();
		cout<< " ";
		it++;
	}
}
