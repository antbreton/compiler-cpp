#ifndef _ETAT_H
#define _ETAT_H
#include <iostream>

class Etat {

	protected :
		string name;
	public :
		Etat (string name);
		virtual ~Etat();
		void print() const;
		virtual bool transition (Automate & automate, Symbole * s);
};

#endif
