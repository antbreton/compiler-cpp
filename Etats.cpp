#include "Etats.h"
#include "Automate.h"
#include <iostream>

using namespace std;


bool E0::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{	
		case (int)'E':
			automate->decalage(s, new E1);
		break;	
		
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
	
	return false;
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
			return true;
		break;	
								
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}



bool E2::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{	
		case (int)'E':
			automate->decalage(s, new E6);
		break;	
		
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
	
	return false;
}


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
				// on ne consume pas le symbole
				automate->push_lexer(s);
				
				cout << "reduction" << endl;
				// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
				automate->reduction(1, new Expr);
			break;		
									
			default:
				automate->erreur = true;
			break;
		}
	return false;
}
	
bool E4::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{	
		case (int)'E':
			automate->decalage(s, new E7);
		break;	
		
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
	
	return false;
}


bool E5::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{	
		case (int)'E':
			automate->decalage(s, new E8);
		break;	
		
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
	
	return false;
}


bool E6::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'+':
			automate->decalage(s, new E4);
		break;	

		case (int)'*':
			automate->decalage(s, new E5);
		break;	
		
		case (int)')': // si on tombe sur le $ final, on accepte l'expression.
			automate->decalage(s, new E9);
		break;	
								
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}

bool E7::transitions(Automate * automate, Symbole * s){	false;}
bool E8::transitions(Automate * automate, Symbole * s){	false;}
bool E9::transitions(Automate * automate, Symbole * s){	false;}
