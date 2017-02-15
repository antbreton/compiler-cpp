// TODO DISPLAY DEQUE BY MODIFING THE PRINTS METHODS
using namespace std;
#include "lexer.h"
#include <iostream>
#include <deque>
#include "Symbole.h"

int main(int argv, char ** args)
{
	cout << "Type a line" << endl;
	std::string line;
	std::getline (std::cin,line);
  
	lexer l(line);
	deque<Symbole> q = l.lecture();
	
	
	deque<Symbole>::iterator it = q.begin();

	while (it != q.end())
	{		
		(*it).print(cout);
		it++;
	}
	
	return 0;
}
