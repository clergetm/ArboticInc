#pragma once
#include <string>
#include <iostream>
using namespace std;

class ColorCell
{
private:
	short int rouge;													// La couleur rouge.
	short int vert;														// La couleur verte.
	short int bleue;													// La couleur bleue.

public:
	ColorCell();														// Constructeur par défaut.
	ColorCell(short int, short int, short int);							// Constructeur avec les valeurs de rouge, vert et bleue.
	~ColorCell();														// Destructeur de ColorCell.

	short int getRouge() const;											// Getter de rouge.
	short int getVert() const;											// Getter de vert.
	short int getBleu() const;											// Getter de bleue.

	void setRouge(short int);											// Setter de rouge, vérifie que la valeur est entre 0 et 255.
	void setVert(short int);											// Setter de vert, vérifie que la valeur est entre 0 et 255.
	void setBleu(short int);											// Setter de bleue, vérifie que la valeur est entre 0 et 255.

	string toString() const;											// Représentation textuelle de ColorCell.

	ColorCell operator + (ColorCell c);									// Surcharge de l’opérateur +.
	friend istream& operator>> (istream& in, ColorCell& colorcell);		// Surcharge de l’opérateur >>.
	friend ostream& operator<< (ostream& out, ColorCell& colorcell);	// Surcharge de l’opérateur <<.

};
