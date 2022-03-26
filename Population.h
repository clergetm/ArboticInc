#pragma once
#include "NoeudPop.h"

using namespace std;

template<class T>
class Population {
public:
	Population();											// Constructeur par défaut
	~Population();											// Destructeur par défaut

	void insererFin(const Arbre<T>&);						// Insérer un nouveau noeud à la fin
	void supprimer(const short int _id);					// Suppression d’un noeud
	NoeudPop<T>* valeurCourante();							// Obtention de la valeur courante

	void fixerTete();										// Fixer courant à tete
	void suivant();											// Changer courant pour le noeud suivant
	bool estDansListe();									// Vérifier si courant est dans la liste
	bool trouver(const short int _id);						// Trouver un élément précis en fonction de l’id 
	bool ancetreCommun(const short int, const short int);	// Trouver l’ancêtre commun
	bool enfantCommun(const short int, const short int);	// Trouver l’enfant commun
private:
	NoeudPop<T>* tete;										// Pointeur tete de liste
	NoeudPop<T>* courant;									// Pointeur courant de liste
	NoeudPop<T>* queue;										// Pointeur queue de liste
};

// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////////

// Constructeur par défaut
template<class T>
Population<T>::Population() {
	tete = nullptr;
	courant = nullptr;
	queue = nullptr;
}

// Destructeur par défaut
template<class T>
Population<T>::~Population(){
	while (tete != nullptr)
	{
		courant = tete;
		tete = tete->suivant;
		delete courant;
	}
}

// FONCTIONS //////////////////////////////////////////////////////////////////////////////////////

/*
* Insérer un Arbre à la fin de la liste
* @param _arbre : un Arbre de cellules
*/
template<class T>
void Population<T>::insererFin(const Arbre<T>& _arbre) {
	queue = queue->suivant = new NoeudPop<T>(_arbre);
}

/*
* Suppression d’un arbre de la liste chaînée
* @param _id : l’id recherché
*/
template<class T>
void Population<T>::supprimer(const short int _id) {
	// Il faut tout d’abord trouver l’élément voulu
	if (trouver(_id)) {
		NoeudPop<T> noeudCourant = valeurCourante();
		courant->suivant = noeudCourant->suivant;

		if (queue == noeudCourant) {
			queue = courant;
		}
		delete noeudCourant;
	}
}

/*
* Obtenir la valeur courante du tableau
*/
template<class T>
NoeudPop<T>* Population<T>::valeurCourante() {
	return courant->suivant;
}

// Transporte le pointeur courant à la tête de la liste
template<class T>
void Population<T>::fixerTete() {
	courant = tete;
}

// Transporte le pointeur courant au noeud suivant dans la liste
template<class T>
void Population<T>::suivant() {
	if(courant != nullptr) courant = courant->suivant;
}

// Retourne true si le pointeur courant est la liste
template<class T>
bool Population<T>::estDansListe() {
	return (courant != nullptr) && (courant->suivant != nullptr);
}

/*
* Trouver l’id recherché parmi les Arbres de la population
* @param _id : l’id recherché
* @returns true dès que le pointeur courant est sur l’arbre dont la racine a l’ID = _id.
* false dès que la liste est parcourue sans plus de résultat.
*/
template<class T>
bool Population<T>::trouver(const short int _id) {
	// On parcours toute la liste
	for (fixerTete(); estDansListe(); suivant()) {
		// On récupère la valeur courante
		NoeudPop<T>* noeudCourant = valeurCourante();
		// On vérifie l’id courant
		if (noeudCourant->arbre->racine.getID() == _id) {
			return true;
		}
	}
	// Aucun résultat, on renvoit false.
	return false;
}

// TO DO //////////////////////////////////////////////////////////////////////////////////////////
/*
* Fonction permettant d’afficher l’ancêtre commun de deux individus
* @param _premier : l’id du premier individu
* @param _second : l’id du second individu
* @returns true si un ancetre commun est trouvé
*/
template<class T>
bool Population<T>::ancetreCommun(const short int _premier, const short int _second) {
	Arbre<T>& premierInd;
	Arbre<T>& secondInd;

	// Récupération des deux élements
	if (trouver(_premier)) {
		premierInd = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_premier) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl; 
		return false;
	}
	if (trouver(_second)) {
		secondInd = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_second) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl;
		return false;
	}

	// On possède les deux arbres, il faut trouver l’ancêtre commun

	// Afficher l’ancêtre commun 
	
	// Si aucun ancêtre commun

}

// TO DO //////////////////////////////////////////////////////////////////////////////////////////
/*
* Fonction permettant d’afficher l’enfant commun de deux individus
* @param _premier : l’id du premier individu
* @param _second : l’id du second individu
* @returns true si un enfant commun est trouvé
*/
template<class T>
bool Population<T>::enfantCommun(const short int _premier, const short int _second) {
	Arbre<T>& premierInd;
	Arbre<T>& secondInd;

	// Récupération des deux élements
	if (trouver(_premier)) {
		premierInd = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_premier) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl;
		return false;
	}
	if (trouver(_second)) {
		secondInd = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_second) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl;
		return false;
	}
	// On possède les deux individus : Il faut trouver l’arbre dans lequel les deux individus apparaîssent.

	// Afficher la différence de génération entre les deux individus

	// Si aucun arbre ne possède les deux individus
}