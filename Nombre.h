#ifndef _NOMBRE_H
#define _NOMBRE_H
#include <iostream>

class Nombre : public Symbole {
	protected : 
		int value;
	public :
		Nombre (int valeur) : Symbole((int)'n'), value(valeur) {}
		void print() { cout << (char) value;}
};

#endif
