#include "Arbotic.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Population.h"
using namespace std;


void Arbotic::ouverture_transactions(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture

	char caractere;
	Population<ChromoCell> chromoPop;
	Population<ColorCell> colorPop;


	short int NB, ID, X, Y;
	string type, txt;

	//Implémentaion des variables nécessaires 


	while (fin >> caractere) {
		switch (caractere) {

			// Créer une population vide de type ...
		case 'C': {
			fin >> currentCell;
			// En soit ne créer pas une nouvelle population mais vide la population courante
			cout << "Créé une population vide de type: " << currentCell << "\n" << endl;
			if (type == "COLORCELL") {
				colorPop = Population<ColorCell>();
			}
			else {
				chromoPop = Population<ChromoCell>();
			}
			break;
		}
				// Ajoute à la population courante un individu sans parent de type... ayant les valeurs ... Population.insererFin(Cellule)
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
				//fin >> cell;
				chromoPop.insererFin(cell);
			}
			break;
		}

				// Ouverture du fichier population
		case 'O': {
			fin >> txt;
			cout << "Ouverture du fichier population " << txt << endl;

			if (type == "COLORCELL") {
				colorPop = O_colorPop(txt);
			}
			else {
				chromoPop = O_chromoPop(txt);
			}
			break;
		}

				// Sauvegarde fichier population
		case 'S': {
			fin >> txt;
			cout << "Sauvegarde du fichier populationn " << txt << endl;
			if (currentCell == "COLORCELL") {

			}
			else {
			}
			break;
		}

				// Génerer NB individues à partir de la population courante 
		case '+': {
			fin >> NB;
			cout << "Génère" << NB << "individues à partir de la population courante \n" << endl;
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
			cout << "Supprime l'individu" << ID << "\n" << endl;
			if (currentCell == "COLORCELL") {
				colorPop.supprimer(NB);
			}
			else {
				chromoPop.supprimer(NB);
			}
			break;
		}

				//  Trouve un ancêtre commun entre deux individus
		case '?': {
			fin >> X >> Y;
			cout << "Ancêtre commmun entre deux individu" << X << "et" << Y << ": \n" << endl;
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
			cout << "Affiche l'arbre génétique complet de l'individu" << X << "incluant ses caractériques: \n" << endl;
			if (currentCell == "COLORCELL") {
				cout << colorPop.toStringIndividu(X) << endl;
			}
			else {
				cout << chromoPop.toStringIndividu(X) << endl;
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

Population<ColorCell> Arbotic::O_colorPop(string _fichierPopulation) {

	ifstream fin(PATH+_fichierPopulation); //Lecture
	Population<ColorCell> colorPop;
	// Variables composant un client
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

	return colorPop;
}

Population<ChromoCell> Arbotic::O_chromoPop(string _fichierPopulation) {

	ifstream fin(PATH+_fichierPopulation); //Lecture
	Population<ChromoCell> chromoPop;
	// Variables composant un client
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
		//fin >> cell;
		noeud->cell = cell;

	}

	// Fermer la lecture du fichier
	fin.close();

	return chromoPop;
}

void Arbotic::S_colorPop(string _nomFichierPopulation, Population<ColorCell>& colorPop) {

	// Création/Ouverture du fichier de sauvegarde
	ofstream sortie;
	sortie.open(PATH+_nomFichierPopulation);

	// On parcourt tous la clients et on sauvegarde les informations
	sortie << "COLORCELL" << colorPop.longueur();


	// Fermeture du fichier
	sortie.close();
}

void Arbotic::S_chromoPop(string _nomFichierPopulation, Population<ChromoCell>& chromoPop) {

}