#pragma once
#include <string>
#include <iostream>
#include "Population.h"
#include "ColorCell.h"
#include "ChromoCell.h"
using namespace std;

class Arbotic
{
private:
	const string PATH = "Fichiers/";					// Constante du chemin relatif des fichiers textes.
	
	string currentCell;									// Indication sur la population courramment utilisé.
	Population<ColorCell> colorPop;						// Population de ColorCell.
	Population<ChromoCell> chromoPop;					// Population de ChromoCell.
	void O_colorPop(string);							// Création de la population de ColorCell à partir d’un fichier.
	void S_colorPop(string);							// Sauvegarde de la population de ColorCell.

	void O_chromoPop(string);							// Création de la population de ChromoCell à partir d’un fichier.
	void S_chromoPop(string);							// Sauvegarde de la population de ChromoCell.

public:
	Arbotic();											// Constructeur par défaut.
	~Arbotic();											// Destructeur par défaut.

	void O_transactions(string _fichierTransaction);	// Lecture des fichiers de transactions.

};
