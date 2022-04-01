#include "Arbotic.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Population.h"
using namespace std;

Arbotic::Arbotic() {
}

Arbotic::~Arbotic() {

	colorPop.viderListe();
	chromoPop.viderListe();
}


void Arbotic::O_transactions(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture

	char caractere;
	short int NB, ID, X, Y;
	string type, txt;

	//Implémentaion des variables nécessaires 


	while (fin >> caractere) {
		switch (caractere) {

		// Créer une population vide de type ...
		case 'C': {
			fin >> currentCell;
			// En soit ne créer pas une nouvelle population mais vide la population courante
			cout << "Créé une population vide de type: " << currentCell << endl;
			if (currentCell == "COLORCELL") {
				colorPop.viderListe();
			}
			else {
				chromoPop.viderListe();
			}
			break;
		}
		
		// Ajoute à la population courante un individu sans parent de type... ayant les valeurs ... 
		case 'A': {
			fin >> type;
			cout << "Ajoute à la population courante un individu sans parents de type : " << type << endl;
			if (type == "COLORCELL") {
				ColorCell cell;
				fin >> cell;
				colorPop.insererFin(cell);
			}
			else {
				ChromoCell cell;
				fin >> cell;
				chromoPop.insererFin(cell);
			}
			break;
		}

		// Ouverture du fichier population
		case 'O': {
			fin >> txt;
			cout << "Ouverture du fichier population " << txt << endl;
			if( txt.find("COLORCELL") != string::npos ) {
				O_colorPop(txt);
				currentCell = " COLORCELL";
			}
			else {
				O_chromoPop(txt);
				currentCell = "CHROMOCELL";
			}
			break;
		}

		// Sauvegarde fichier population
		case 'S': {
			fin >> txt;
			cout << "Sauvegarde du fichier population " << txt << endl;
			if (currentCell == "COLORCELL") {
				S_colorPop(txt);
				colorPop.viderListe();
			}
			else {
				S_chromoPop(txt);
				chromoPop.viderListe();
			}
			break;
		}

		// Génerer NB individues à partir de la population courante 
		case '+': {
			fin >> NB;
			cout << "Génère " << NB << " individus à partir de la population courante" << endl;
			if (currentCell == "COLORCELL") {
				colorPop.generer(NB);
			}
			else {
				chromoPop.generer(NB);
			}

			break;
		}

		//  Supprime un individu X
		case '-': {
			fin >> ID;
			cout << "Supprime l'individu " << ID << endl;
			if (currentCell == "COLORCELL") {
				colorPop.supprimer(ID);
			}
			else {
				chromoPop.supprimer(ID);
			}
			break;
		}

		//  Trouve un ancêtre commun entre deux individus
		case '?': {
			fin >> X >> Y;
			cout << "Ancêtre commmun entre deux individus " << X << " et " << Y << endl;
			if (currentCell == "COLORCELL") {
				colorPop.ancetreETenfantCommuns(X, Y);
			}
			else {
				chromoPop.ancetreETenfantCommuns(X, Y);
			}
			break;
		}

		//  Affiche l'arbre génétique complet de l'individu X
		case '$': {
			fin >> X;
			cout << "Affiche l'arbre génétique complet de l'individu " << X << " incluant ses caractériques" << endl;
			if (currentCell == "COLORCELL") {
				cout << colorPop.toStringIndividu(X) << "\n" << endl;
			}
			else {
				cout << chromoPop.toStringIndividu(X) << "\n" << endl;
			}
			break;
		}

		// Cas erreur
		default: {
			cout << "\n Une erreur est survenue. Fin forcée de la transation. \n";
			fin.close();
			return;
		}
		}
	}

	fin.close();
}

void Arbotic::O_colorPop(string _fichierPopulation) {
	ifstream fin(PATH + _fichierPopulation); //Lecture

	// Variables composant une Population
	string type;
	short int NB, ID;
	char IDGauche, IDDroit;
	fin >> type >> NB;

	// Tant que l’on peut recupérer les informations
	while (fin >> ID) {
		// Créer un nouveau noeud avec cet ID.
		Noeud<ColorCell>* noeud = new Noeud<ColorCell>(ID);
		colorPop.insererFin(noeud);

		// Ancêtre de Gauche
		fin >> IDGauche;
		if (IDGauche != '/'){
			if (colorPop.trouver(IDGauche)) {
				noeud->ancGauche = colorPop.valeurCourante()->getR();
			}
		}
		
		// Ancêtre de Droite
		fin >> IDDroit;
		if (IDDroit != '/') {
			if (colorPop.trouver(IDDroit)) {
				noeud->ancDroite = colorPop.valeurCourante()->getR();
			}
		}

		// Les valeurs de la Cellule
		ColorCell cell;
		fin >> cell;
		noeud->cell = cell;

	}
	
	// Fermer la lecture du fichier
	fin.close();
}

void Arbotic::S_colorPop(string _nomFichierPopulation) {
	// Création/Ouverture du fichier de sauvegarde
	ofstream sortie;
	sortie.open(PATH+_nomFichierPopulation);

	// On parcourt tous la clients et on sauvegarde les informations
	sortie << "COLORCELL" << " " << colorPop.longueur() << "\n";

	for (colorPop.fixerTete(); colorPop.estDansListe(); colorPop.suivant()) {
		auto NoeudPop = colorPop.valeurCourante();

		sortie << NoeudPop->getR()->toString() << "\n";
	}

	// Fermeture du fichier
	sortie.close();
}

void Arbotic::O_chromoPop(string _fichierPopulation) {
	ifstream fin(PATH + _fichierPopulation); //Lecture

		// Variables composant une Population
	string type;
	short int NB, ID;
	char IDGauche, IDDroit;
	fin >> type >> NB;

	// Tant que l’on peut recupérer les informations
	while (fin >> ID) {
		// Créer un nouveau noeud avec cet ID.
		Noeud<ChromoCell>* noeud = new Noeud<ChromoCell>(ID);
		chromoPop.insererFin(noeud);

		// Ancêtre de Gauche
		fin >> IDGauche;
		if (IDGauche != '/') {
			if (chromoPop.trouver(IDGauche)) {
				noeud->ancGauche = chromoPop.valeurCourante()->getR();
			}
		}

		// Ancêtre de Droite
		fin >> IDDroit;
		if (IDDroit != '/') {
			if (chromoPop.trouver(IDDroit)) {
				noeud->ancDroite = chromoPop.valeurCourante()->getR();
			}
		}

		// Les valeurs de la Cellule
		ChromoCell cell;
		fin >> cell;
		noeud->cell = cell;

	}

	// Fermer la lecture du fichier
	fin.close();
}

void Arbotic::S_chromoPop(string _nomFichierPopulation) {
	// Création/Ouverture du fichier de sauvegarde
	ofstream sortie;
	sortie.open(PATH + _nomFichierPopulation);

	// On parcourt tous la clients et on sauvegarde les informations
	sortie << "COLORCELL" << " " << chromoPop.longueur() << "\n";

	for (chromoPop.fixerTete(); chromoPop.estDansListe(); chromoPop.suivant()) {
		auto NoeudPop = chromoPop.valeurCourante();

		sortie << NoeudPop->getR()->toString() << "\n";
	}

	// Fermeture du fichier
	sortie.close();
}
