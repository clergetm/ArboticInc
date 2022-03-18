#pragma once
#include <string>
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

	/**
	* Surcharge de l'opérateur +
	* Retourne une nouvelle ColorCell
	* @param c : la seconde ColorCell
	*/
	ColorCell operator + (ColorCell c) {
		// Initialisation des différentes couleurs
		short int _rouge;
		short int _vert;
		short int _bleu;

		//Initialisation des différents opérateurs de couleurs

		//Rouge
		_rouge = (this->rouge + (c.getRouge())) / 2;

		//Vert
		_vert = (this->vert + (c.getVert())) / 2;

		//Bleu
		_bleu = (this->bleu + (c.getBleu())) / 2;

		return ColorCell(_rouge, _vert, _bleu);
	}



};
