#include "Arbotic.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Population.h"
using namespace std;

void Arbotic::ouverture_population(string _fichierPopulation) {

	ifstream fin(_fichierPopulation); //Lecture

	// Variables composant un client
	string type;
	short int NB;
	int num;
	int i = 1;
	fin >> type >> NB;

	// Tant que l’on peut recupérer les informations
	while (i < NB + 1) {

	}
	

	// Fermer la lecture du fichier
	fin.close();
}

void Arbotic::sauvegarde_population(string _nomFichierPopulation) {

	// Création/Ouverture du fichier de sauvegarde
	ofstream sortie;
	sortie.open(_nomFichierPopulation);

	// On parcourt tous la clients et on sauvegarde les informations
	

	// Fermeture du fichier
	sortie.close();
}




void Arbotic::ouverture_transactions(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture

	char caractere;
	

	short int NB;
	int ID;
	int X;
	int Y;
	string type;

	//Implémentaion des variables nécessaires 
	

	while (fin >> caractere) {
		switch (caractere) {

			// Créer une population vide de type ...
		case 'C': {
			fin >> type;
			cout << "Créer une population vide de type:" << type << "\n" << endl;

			break;
		}

				// Ajoute à la population courante un individu sans parent de type... ayant les valeurs ... Population.insererFin(Cellule)
		case 'A': {
			fin >> type;
			cout << "Ajoute à la population courante un individu sans parents de type" << type << "ayant les valeurs:" << endl;
			population.insererFin(Cellule);
			break;
		}

				// Ouverture du fichier population
		case 'O': {
			cout << "Ouverture du fichier population \n" << endl;
			fin >> nomFichierPopulation;
			ouverture_population(nomFichierPopulation);
			break;
		}

				// Sauvegarde fichier population
		case 'S': {
			cout << "Sauvegarde du fichier population \n" << endl;
			fin >> nomFichierPopulation;
			sauvegarde_population(nomFichierPopulation);
			break;
		}

				// Génerer NB individues à partir de la population courante 
		case '+': {
			fin >> NB;
			cout << "Génère" << NB << "individues à partir de la population courante \n" << endl;
			population.generer(NB);

			break;
		}

				//  Supprime un individu X
		case '-': {
			fin >> ID;
			cout << "Supprime l'individu" << ID << "\n" << endl;
			population.supprimer(ID);
			break;
		}

				//  Trouve un ancêtre commun entre deux individus
		case '?': {
			fin >> X >> Y;
			cout << "Ancêtre commmun entre deux individu" << X << "et" << Y << ": \n" << endl;
			population.ancetreETenfantCommuns(X,Y);
			break;
		}

				//  Affiche l'arbre génétique complet de l'individu X
		case '$': {
			fin >> X;
			cout << "Affiche l'arbre génétique complet de l'individu" << X << "incluant ses caractériques: \n" << endl;
			population.toStringIndividu(X);
			break;
		}

				// Cas erreur
		default: {
			cout << "\n fin de la liste transaction \n";
			fin.close();
			return;
		}
		}
	}

	cout << "\n Merci Isaaaaaaa :)" << endl;
	fin.close();
}