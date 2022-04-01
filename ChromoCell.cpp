#include "ChromoCell.h"
#include <iostream>
using namespace std;

// CONSTRUCTEURS DESTRUCTEURS //////////////////////////

// Constructeur par défaut
ChromoCell::ChromoCell() {
	this->paireUne[0] = 0;
	this->paireUne[1] = 0;
	this->paireDeux[0] = 0;
	this->paireDeux[1] = 0;
	this->paireTrois[0] = 0;
	this->paireTrois[1] = 0;
	this->paireQuatre[0] = 0;
	this->paireQuatre[1] = 0;

}

/**
* Constructeur de Noeud avec id et valeur.
* @param _paireUne:
* @param _paireDeux:		
* @param _paireTrois:		
* @param _paireQuatre:		
*/

ChromoCell::ChromoCell(char _paireUne0, char _paireUne1, char _paireDeux0, char _paireDeux1, char _paireTrois0, char _paireTrois1, char _paireQuatre0, char _paireQuatre1) {
	this->paireUne[0] = _paireUne0;
	this->paireUne[1] = _paireUne1;
	this->paireDeux[0] = _paireDeux0;
	this->paireDeux[1] = _paireDeux1;
	this->paireTrois[0] = _paireTrois0;
	this->paireTrois[1] = _paireTrois1;
	this->paireQuatre[0] = _paireQuatre0;
	this->paireQuatre[1] = _paireQuatre1;
}


// Destructeur par défaut.
ChromoCell::~ChromoCell(){}

// GETTERS SETTERS //////////////////////////////////////////////////////////////////////

// Getter de paireUne

char ChromoCell::getPaireUne() const { return paireUne[0];  }

// Getter de paireDeux

char ChromoCell::getPaireDeux() const { return paireDeux[0]; }

// Getter de paireTrois

char ChromoCell::getPaireTrois() const { return paireTrois[0]; }

// Getter de paireQuatres

char ChromoCell::getPaireQuatre() const { return paireQuatre[0]; }

/**
* Setter de paireUne.
* Verifie si la valeur est bien entre A et L avant de l'utiliser.
* @param _valeur : char.
*/

void ChromoCell::setPaireUne(char _valeur) {
	if ( _valeur=='A' || _valeur == 'B' || _valeur == 'C' || _valeur == 'D' || _valeur == 'E' || _valeur == 'F' || _valeur == 'G' || _valeur == 'H' || _valeur == 'I' || _valeur == 'J' || _valeur == 'K' || _valeur == 'L') {
		paireUne[0] = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour paireUne : " + _valeur << endl;
	}
}

/**
* Setter de paireDeux.
* Verifie si la valeur est bien entre A et L avant de l'utiliser.
* @param _valeur : char.
*/

void ChromoCell::setPaireDeux(char _valeur) {
	if (_valeur == 'A' || _valeur == 'B' || _valeur == 'C' || _valeur == 'D' || _valeur == 'E' || _valeur == 'F' || _valeur == 'G' || _valeur == 'H' || _valeur == 'I' || _valeur == 'J' || _valeur == 'K' || _valeur == 'L') {
		paireDeux[0] = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour paireDeux : " + _valeur << endl;
	}
}

/**
* Setter de paireTrois.
* Verifie si la valeur est bien entre A et L avant de l'utiliser.
* @param _valeur : char.
*/

void ChromoCell::setPaireTrois(char _valeur) {
	if (_valeur == 'A' || _valeur == 'B' || _valeur == 'C' || _valeur == 'D' || _valeur == 'E' || _valeur == 'F' || _valeur == 'G' || _valeur == 'H' || _valeur == 'I' || _valeur == 'J' || _valeur == 'K' || _valeur == 'L') {
		paireTrois[0] = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour paireTrois : " + _valeur << endl;
	}
}

/**
* Setter de paireQuatre.
* Verifie si la valeur est bien entre A et L avant de l'utiliser.
* @param _valeur : char.
*/

void ChromoCell::setPaireQuatre(char _valeur) {
	if (_valeur == 'A' || _valeur == 'B' || _valeur == 'C' || _valeur == 'D' || _valeur == 'E' || _valeur == 'F' || _valeur == 'G' || _valeur == 'H' || _valeur == 'I' || _valeur == 'J' || _valeur == 'K' || _valeur == 'L') {
		paireQuatre[0] = _valeur;
	}
	else {
		cout << "Insertion impossible de la valeur pour paireQuatre : " + _valeur << endl;
	}
}

// FONCTIONS //////////////////////////////////////////////////////////////////////////////////////

/*
* Représentation textuelle de ChromoCell.
* @returns le string de ChromoCell.
*/