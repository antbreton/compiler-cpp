#include "lexer.h"
#include "Nombre.h"
#include <stdlib.h>    /* atoi */
#include <iostream>
#include <cstdio>

deque<Symbole*> lexer::lecture()
{	
	deque<Symbole*> expression;
		
	while(teteLecture < line.length())
	{		
		next();
		expression.push_back(prochain);
		shift();
	}
	return expression;
}

lexer::lexer(std::string flux)
{
	this->line = flux;
	this->teteLecture = 0;
}

void lexer::next()
{
	if(ok == false)
		checkNext();	
	ok = true;
}

void lexer::shift()
{
	teteLecture++;
	ok = false;
}

void lexer::checkNext()
{
	//  Etape 1
	//if( (int)*prochain == (int)'(' || (int)*prochain == (int)')'|| (int)*prochain == (int)'+'|| (int)*prochain == (int)'*')
	if(line[teteLecture] == '(' || line[teteLecture] == ')' || line[teteLecture] == '+' || line[teteLecture] == '*')
	{
		prochain=new Symbole((int)line[teteLecture]);
		return;
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
		return;
	}
	// Etape 3
	if(line[teteLecture] == EOF)
	{
		prochain=new Symbole((int)'$');
		return;
	}
	cout << "lex erreur at : "<< line[teteLecture]<< "\t";
}

