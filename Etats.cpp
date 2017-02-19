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
				// on ne consume pas le symbole
				automate->push_lexer(s);
				
				automate->pop_destroy_symbol();
				
				cout << "reduction" << endl;
				// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
				automate->reduction(1, new Expr);
			break;	

			case (int)'*':
				// on ne consume pas le symbole
				automate->push_lexer(s);
				
				automate->pop_destroy_symbol();
				
				cout << "reduction" << endl;
				// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
				automate->reduction(1, new Expr);
			break;	
		
			case (int)')':
				// on ne consume pas le symbole
				automate->push_lexer(s);
				
				
				automate->pop_destroy_symbol();
				
				cout << "reduction" << endl;
				// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
				automate->reduction(1, new Expr);
			break;	
			
			case (int)'$':
				// on ne consume pas le symbole
				automate->push_lexer(s);
				
				automate->pop_destroy_symbol();
				
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
		
		case (int)')':
			automate->decalage(s, new E9);
		break;	
								
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}

bool E7::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'+':
		{
		// REDUCTION 2
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E+E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprPlus(e1,e2));
			break;	
		}
		
		case (int)'*':
		{	
			automate->decalage(s, new E5);
			break;	
		}
		
		case (int)')':
		{
		// REDUCTION 2
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E+E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprPlus(e1,e2));
			break;
		}
		
		case (int)'$':
		{		// REDUCTION 2
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E+E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprPlus(e1,e2));			
			break;
		}
							
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}


bool E8::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'+':
		{		// REDUCTION 3
			// on ne consume pas le symbole
			automate->push_lexer(s);
			cout << ".";
			// On construit l'epression addition // E*E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			cout << ".";
			automate->pop_destroy_symbol();
			cout << ".";
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			cout << ".";
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprMul(e1,e2));		
			break;	
		}

		case (int)'*':
		{		// REDUCTION 3
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E*E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprMul(e1,e2));		
			break;	
		}
		
		case (int)')':
		{		// REDUCTION 3
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E*E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprMul(e1,e2));		
			break;	
		}
		case (int)'$':
		{		// REDUCTION 3
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // E*E
			Expr * e1 = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol(); 
			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, new ExprMul(e1,e2));		
			break;	
		}			
							
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}

bool E9::transitions(Automate * automate, Symbole * s)
{
	switch(*s)
	{
		case (int)'+':
		{		// REDUCTION 4
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();

			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, e);		
			break;	
		}
		
		case (int)'*':
		{		// REDUCTION 4
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();

			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, e);		
			break;	
		}
		
		case (int)')':
		{		// REDUCTION 4
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();

			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, e);		
			break;	
		}

		case (int)'$':
		{		// REDUCTION 4
			// on ne consume pas le symbole
			automate->push_lexer(s);
			
			// On construit l'epression addition // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol(); 
			automate->pop_destroy_symbol();

			
			cout << "reduction" << endl;
			// règle de réduction 5 : on remplace la valeur par E, et on pop de 1				
			automate->reduction(3, e);		
			break;	
		}			
							
		default:
			automate->erreur = true;
		break;
	}	
	return false;
}

