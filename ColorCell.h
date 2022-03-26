#pragma once
#include <string>
#include <iostream>
using namespace std;

class ColorCell
{
private:
	short int rouge;
	short int vert;
	short int bleu;

public:
	ColorCell();									// Constructeur par défaut
	ColorCell(short int, short int, short int);		// Constructeur avec les valeurs de rouge, vert et bleu
	~ColorCell();									// Destructeur de ColorCell

	short int getRouge() const;						// Getter de rouge
	short int getVert() const;						// Getter de vert
	short int getBleu() const;						// Getter de bleu

	void setRouge(short int);						// Setter de rouge, vérifie que la valeur est entre 0 et 255
	void setVert(short int);						// Setter de vert, vérifie que la valeur est entre 0 et 255
	void setBleu(short int);						// Setter de bleu, vérifie que la valeur est entre 0 et 255

	string toString() const;						// Représentation textuelle de ColorCell

	ColorCell operator + (ColorCell c);

	friend istream& operator>> (istream& in, ColorCell& colorcell);


	friend ostream& operator<< (ostream& out, ColorCell& colorcell);

};





