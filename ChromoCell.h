#pragma once
#include <string>
#include <iostream>
using namespace std;

class ChromoCell
{
private:
	string listChromo() const;											// Obtenir les 4 paires en une liste.
	bool pileOuFace() const;											// Un pile ou face utilisé pour la génération aléatoire.
	char paireUne[2];													// Première Paire de Chromosome.
	char paireDeux[2];													// Deuxième Paire de Chromosome.
	char paireTrois[2];													// Troisième Paire de Chromosome.
	char paireQuatre[2];												// Quatrième Paire de Chromosome.

public:
	ChromoCell();														// Constructeur par défaut.
	ChromoCell(char[], char[], char[], char[]);							// Constructeur avec les 4 paires.
	~ChromoCell();														// Destructeur par défaut.

	string toString() const;											// Représentation textuelle de ColorCell.

	ChromoCell operator + (ChromoCell c);								// Surcharge de l’opérateur +.
	friend istream& operator>> (istream& in, ChromoCell& chromocell);	// Surcharge de l’opérateur >>.
	friend ostream& operator<< (ostream& out, ChromoCell& chromocell);	// Surcharge de l’opérateur <<.

};
