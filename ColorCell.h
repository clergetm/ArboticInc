#pragma once
#include <string>
using namespace std;

class ColorCell
{
private:
	short int rouge = 0;
	short int vert = 0;
	short int bleu = 0;

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
};
