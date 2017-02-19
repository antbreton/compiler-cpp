#include "lexer.h"
#include <stdlib.h>    /* atoi */
#include <iostream>
#include <cstdio>

deque<Symbole*>* lexer::lecture()
{	
	if(line[line.length()-1] != '$')
		line.append("$");
		
	while(teteLecture < line.length())
	{		
		if(next())
			expression->push_back(prochain);
		shift();
	}
	return expression;
}

lexer::lexer(std::string flux)
{
	expression = new deque<Symbole*>();
	this->line = flux;
	this->teteLecture = 0;
}

lexer::~lexer()
{
	deque<Symbole*>::iterator it = expression->begin();
	
	while (it != expression->end())
	{		
		delete(*it);
		it++;
	}
}


// Return true if a symbole is created.
bool lexer::next()
{
		return checkNext();	
}

void lexer::shift()
{
	teteLecture++;

}

// Check the car at the read head. It creates a token if we recognize something.
// Return true if a symbole is created. It could be false if we don't recognize any symbole that matchs with the grammar
bool lexer::checkNext()
{
	//  Etape 1
	if(line[teteLecture] == '(' || line[teteLecture] == ')' || line[teteLecture] == '+' || line[teteLecture] == '*')
	{
		prochain=new Symbole((int)line[teteLecture]);
		return true;
	}
	
	// Etape 2
	if(isdigit(line[teteLecture]))
	{
		string number = "";	
		number +=line[teteLecture];
		
		while(isdigit(line[teteLecture+1]))
		{
			number+=line[teteLecture+1];
			teteLecture++;
		}
		prochain=new Nombre(atoi(number.c_str()));
		return true;
	}
	// Etape 3
	if(line[teteLecture] == EOF || line[teteLecture] == '$' || line[teteLecture] == '\0')
	{
		prochain=new Symbole((int)'$');
		return true;
	}
	nbError++;
	
	cout << "\tlex erreur at : "<< line[teteLecture]<<endl;

	return false;
}

