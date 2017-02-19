#include "Etats.h"
#include "Automate.h"
#include <iostream>


bool E0::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'(':
			automate->decalage(s, new E2);
		break;	

		case (int)'n':
			automate->decalage(s, new E3);
		break;	
						
		default:
			automate->erreur = true;
		break;
	}	
	
	false;
}


bool E1::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'+':
			automate->decalage(s, new E4);
		break;	

		case (int)'*':
			automate->decalage(s, new E5);
		break;	
		
		case (int)'$': // si on tombe sur le $ final, on accepte l'expression.
			std::cout << "working" << std::endl;
			return true;
		break;	
								
		default:
			automate->erreur = true;
		break;
	}	
	false;
}



bool E2::transitions(Automate * automate, Symbole * s){	automate->erreur = true; return false;}


bool E3::transitions(Automate * automate, Symbole * s)
{		
	switch(*s)
		{
			case (int)'+':
				automate->decalage(s, new E4);
			break;	

			case (int)'*':
				automate->decalage(s, new E5);
			break;	
		
			case (int)')':
				automate->decalage(s, new E4);
			break;	
			
			case (int)'$':

			break;		
									
			default:
				automate->erreur = true;
			break;
		}
}
	
bool E4::transitions(Automate * automate, Symbole * s){	automate->erreur = true; return false;}
bool E5::transitions(Automate * automate, Symbole * s){	automate->erreur = true; return false;}
bool E6::transitions(Automate * automate, Symbole * s){	false;}
bool E7::transitions(Automate * automate, Symbole * s){	false;}
bool E8::transitions(Automate * automate, Symbole * s){	false;}
bool E9::transitions(Automate * automate, Symbole * s){	false;}
