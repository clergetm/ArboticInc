#include "ColorCell.h"
#include <iostream>
using namespace std;

// Getter de rouge
short int ColorCell::GetRouge() const { return rouge; }

// Getter de vert
short int ColorCell::GetVert() const { return vert; }

// Getter de bleu
short int ColorCell::GetBleu() const { return bleu; }

/**
* Setter de rouge
* Verifie si la valeur est bien entre 0 et 255 avant de l'utiliser
* @param _valeur : short int
*/
void ColorCell::SetRouge(short int _valeur) {
	if (0 >= _valeur <= 255) {
		rouge = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour ROUGE : " + _valeur << endl;
	}
}

/**
* Setter de vert
* Verifie si la valeur est bien entre 0 et 255 avant de l'utiliser
* @param _valeur : short int
*/
void ColorCell::SetVert(short int _valeur) {
	if (0 >= _valeur <= 255) {
		vert = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour VERT : " + _valeur << endl;
	}
}

/**
* Setter de bleu
* Verifie si la valeur est bien entre 0 et 255 avant de l'utiliser
* @param _valeur : short int
*/
void ColorCell::SetBleu(short int _valeur) {
	if (0 >= _valeur <= 255) {
		bleu = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour BLEU : " + _valeur << endl;
	}
}

// Représentation textuelle de ColorCell
string ColorCell::ToString() const {
	return to_string(rouge) + " " + to_string(vert) + " " + to_string(bleu);
}