#ifndef _LEXER_H
#define _LEXER_H

#include <istream>
#include "Symbole.h"
#include <deque>

using namespace std;

class lexer
{
	public :
		deque<Symbole> lecture();
		lexer(std::string flux);
		void checkNext();
	private :
		std::string line;
		Symbole * prochain;
		bool ok;
		void next();
		void shift();
		int teteLecture;
};

#endif
