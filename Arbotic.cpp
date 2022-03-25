#include "Arbotic.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void Population::ouverture_transactions(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture

	char caractere;
	//Implémentaion dans supprimerClient insérerClient
	string nomClient;
	//Implémentaion dans insérerClient
	short int numero;
	string rue;

	//Implémentaion des variables nécessaires 
	string source;
	string nomFichierClient;
	string nomFichierCommande;
	string destinataire;
	string nomCookie;
	string courant;
	short int quantiteCookie;

	while (fin >> caractere) {
		switch (caractere) {

			// Suppression d'un Client
		case 'C': {
			
			break;
		}

				// Ajout d'un Client
		case 'A': {
			
			break;
		}

				// Ajout d'une commande d'un client
		case 'O': {
			cout << "Ouverture du fichier population \n" << end1;
			fin >> nomFichierPopulation;
			ouverture_population(nomFichierPopulation);
			break;
		}

				// Afficher les commandes faites par un Client
		case 'S': {
			cout << "Sauvegarde du fichier population \n" << end1;
			fin >> nomFichierPopulation;
			sauvegarde_population(nomFichierPopulation);
			break;
		}

				// Afficher les informations du meilleur cookie
		case '+': {
			
			break;
		}

				// Ouverture des fichiers de Clients et Commandes
		case '-': {
			
			break;
		}

				// Sauvegarde des Clients et Commandes
		case 'S': {
			
			break;
		}

				// Sauvegarde des Clients et Commandes
		case '?': {
			
			break;
		}

				// Sauvegarde des Clients et Commandes
		case '$': {
			
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