#ifndef _LEXER_H
#define _LEXER_H

#include <istream>
#include "Symbole.h"
#include <deque>

using namespace std;

class lexer
{
	public :
		deque<Symbole*> lecture();
		lexer(std::string flux);
		~lexer();
		bool checkNext();
	private :
		std::string line;
		Symbole * prochain;
		bool ok;
		bool next();
		void shift();
		int teteLecture;
		deque<Symbole*> expression;
};

#endif
