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

		case (int)'$': // if we find the final $, we accept the expression.
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
			{
				// we don't consume the symbol
				automate->push_lexer(s);

				Nombre * n = (Nombre *)automate->pop_symbol();

				// rule of reduction 5 : we replace the value by E and we pop by 1.
				automate->reduction(1, new ExprVal(n->getValue()));
				break;
			}
			case (int)'*':
			{	// we don't consume the symbol
				automate->push_lexer(s);

				Nombre * n = (Nombre *)automate->pop_symbol();

				// rule of reduction 5 : we replace the value by E and we pop by 1.
				automate->reduction(1, new ExprVal(n->getValue()));
				break;
			}
			case (int)')':
			{	// we don't consume the symbol
				automate->push_lexer(s);

				Nombre * n = (Nombre *)automate->pop_symbol();

				// rule of reduction 5 : we replace the value by E and we pop by 1.
				automate->reduction(1, new ExprVal(n->getValue()));
				break;
			}
			case (int)'$':
			{	// we don't consume the symbol
				automate->push_lexer(s);

				Nombre * n = (Nombre *)automate->pop_symbol();

				// rule of reduction 5 : we replace the value by E and we pop by 1.
				automate->reduction(1, new ExprVal(n->getValue()));
				break;
			}

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
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E+E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
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
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E+E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, new ExprPlus(e1,e2));
			break;
		}

		case (int)'$':
		{		// REDUCTION 2
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E+E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
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
			// we don't consume the symbol
			automate->push_lexer(s);
			// We build the addition expression // E*E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, new ExprMul(e1,e2));
			break;
		}

		case (int)'*':
		{		// REDUCTION 3
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E*E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, new ExprMul(e1,e2));
			break;
		}

		case (int)')':
		{		// REDUCTION 3
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E*E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, new ExprMul(e1,e2));
			break;
		}
		case (int)'$':
		{		// REDUCTION 3
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // E*E
			Expr * e1 = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();
			Expr * e2 = (Expr *)automate->pop_symbol();


			// rule of reduction 5 : we replace the value by E and we pop by 1.
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
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, e);
			break;
		}

		case (int)'*':
		{		// REDUCTION 4
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, e);
			break;
		}

		case (int)')':
		{		// REDUCTION 4
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, e);
			break;
		}

		case (int)'$':
		{		// REDUCTION 4
			// we don't consume the symbol
			automate->push_lexer(s);

			// We build the addition expression // (E)
			automate->pop_destroy_symbol();
			Expr * e = (Expr *) automate->pop_symbol();
			automate->pop_destroy_symbol();

			// rule of reduction 5 : we replace the value by E and we pop by 1.
			automate->reduction(3, e);
			break;
		}

		default:
			automate->erreur = true;
		break;
	}
	return false;
}

