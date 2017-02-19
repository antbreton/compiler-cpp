#ifndef _ETATS_H
#define _ETATS_H

#include "Symbole.h"

class Automate;

class Etat
{
	public :
		Etat(std::string name):name(name){}
		virtual ~Etat() {}
		void print() const;
		virtual bool transitions(Automate * automate, Symbole * s) = 0;
		std::string getName(){ return name;}
	protected :
		std::string name;
};


// Definitions of classes of the different states
class E0: public Etat
{
	public :
		E0():Etat("E0") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E1: public Etat
{
	public :
		E1():Etat("E1") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E2: public Etat
{
	public :
		E2():Etat("E2") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E3: public Etat
{
	public :
		E3():Etat("E3") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E4: public Etat
{
	public :
		E4():Etat("E4") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E5: public Etat
{
	public :
		E5():Etat("E5") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E6: public Etat
{
	public :
		E6():Etat("E6") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E7: public Etat
{
	public :
		E7():Etat("E7") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E8: public Etat
{
	public :
		E8():Etat("E8") {}
		bool transitions(Automate * automate, Symbole * s);
};

class E9: public Etat
{
	public :
		E9():Etat("E9") {}
		bool transitions(Automate * automate, Symbole * s);
};

#endif
