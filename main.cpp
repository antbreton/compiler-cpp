
using namespace std;

#include <iostream>
#include <deque>

#include "lexer.h"
#include "Symbole.h"
#include "Automate.h"


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
	
	cout << "Step 2 : Synthaxical analysis" << endl;
	Automate automate(&q);
	automate.analyse();
	
	
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
