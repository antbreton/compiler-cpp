
// Defines
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"
#define BOLD   "\033[1m\033[37m"

using namespace std;

#include <iostream>
#include <deque>

#include "lexer.h"
#include "Symbole.h"
#include "Automate.h"


//Prototypes--
void displaySymboles(deque<Symbole*>* q);
// -----------


// Entry point of the program, it executes the different steps : lexer,
int main(int argv, char ** args)
{
	cout << BOLD <<"Step 0 : Type a line" << RESET<< endl<<'\t';
	std::string line;
	std::getline (std::cin,line);

  // STEP 1 ---------------- LEXICAL ANALYSIS -----------------------
  cout <<endl<< BOLD << "Step 1 : lexical analysis" << RESET <<endl;
	lexer l(line);
	deque<Symbole*>* q = l.lecture();
	displaySymboles(q);

	// Display the results of the lexical analysis
	if(l.getNbError()==0)
		cout << endl << endl << GREEN << "\tAccepted" << RESET << endl<<endl;
	else
		cout << endl << endl << GREEN << "\tAccepted" << RESET << " with "<< l.getNbError() <<" error(s)"<< endl<<endl;


	// STEP 2 ----------------- SYNTAX ANALYSIS	------------------------
	cout <<  BOLD <<"Step 2 : Syntax analysis" << RESET<< endl;
	Automate automate(q);

	if(!automate.analyse()) { return 1; } // On s'arrête s'il y a une erreur

	// STEP 3 ----------------- RESULT -------------------------------
	// if not we display the result
	cout <<  BOLD <<"Step 3 : Result" <<RESET<< endl;
	automate.calculate();

	return 0;
}

// This function displays the symbol list
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
