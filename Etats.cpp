#include "Etats.h"
#include "Automate.h"
#include <iostream>


bool E0::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'(':
		std::cout << "found (";
		break;	
	}
	
	automate->erreur = true;
	false;
}


bool E1::transitions(Automate * automate, Symbole * s){	false;}
bool E2::transitions(Automate * automate, Symbole * s){	false;}
bool E3::transitions(Automate * automate, Symbole * s){	false;}
bool E4::transitions(Automate * automate, Symbole * s){	false;}
bool E5::transitions(Automate * automate, Symbole * s){	false;}
bool E6::transitions(Automate * automate, Symbole * s){	false;}
bool E7::transitions(Automate * automate, Symbole * s){	false;}
bool E8::transitions(Automate * automate, Symbole * s){	false;}
bool E9::transitions(Automate * automate, Symbole * s){	false;}
