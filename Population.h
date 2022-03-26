#pragma once
#include "NoeudPop.h"

using namespace std;

template<class T>
class Population {
public:
	Population();														// Constructeur par défaut
	~Population();														// Destructeur par défaut

	void insererFin(const Arbre<T>&);									// Insérer un nouveau noeud à la fin
	void supprimer(const short int _id);								// Suppression d’un noeud
	NoeudPop<T>* valeurCourante();										// Obtention de la valeur courante

	void fixerTete();													// Fixer courant à tete
	void suivant();														// Changer courant pour le noeud suivant
	bool estDansListe();												// Vérifier si courant est dans la liste
	bool trouver(const short int _id);									// Trouver un élément précis en fonction de l’id 
	bool ancetreCommun(const short int, const short int);				// Trouver l’ancêtre commun
	short int aideAncetreCommun(Arbre<T>& _premier, Arbre<T>& _second);	// Fonction récursive pour trouver un ancetre commun

	bool enfantCommun(const short int, const short int);				// Trouver l’enfant commun
private:
	NoeudPop<T>* tete;													// Pointeur tete de liste
	NoeudPop<T>* courant;												// Pointeur courant de liste
	NoeudPop<T>* queue;													// Pointeur queue de liste
};

// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////////

// Constructeur par défaut
template<class T>
Population<T>::Population() {
	tete = courant = queue = new NoeudPop<T>();
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
		if (noeudCourant->arbre.racine->getID() == _id) {
			return true;
		}
	}
	// Aucun résultat, on renvoit false.
	return false;
}

/*
* Fonction permettant d’afficher l’ancêtre commun de deux individus
* @param _premierID : l’id du premier individu
* @param _secondID : l’id du second individu
* @returns true si un ancetre commun est trouvé
*/
template<class T>
bool Population<T>::ancetreCommun(const short int _premierID, const short int _secondID) {
	Arbre<T> premier = Arbre<T>();
	Arbre<T> second = Arbre<T>();

	// Récupération des deux élements
	if (trouver(_premierID)) {
		premier = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_premierID) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl; 
		return false;
	}
	if (trouver(_secondID)) {
		second = valeurCourante()->arbre;
	}
	else {
		cout << "L’individu " << to_string(_secondID) << " n’a pas été trouvé." << endl;
		cout << "Fin de la recherche." << endl;
		return false;
	}

	// On possède les deux arbres, il faut trouver l’ancêtre commun
	cout << "Pour les individus " << to_string(_premierID) << " et " << to_string(_secondID) << ":" << endl;
	// Afficher l’ancêtre commun 
	short int anc = aideAncetreCommun(premier, second);
	if (anc > 0) {
		cout << " - Il existe un ancêtre commun qui est " << to_string(anc) << "." << endl;
		return true;
	
	} 
	// Si aucun ancêtre commun
	else {
		cout << " - Il n’existe aucun ancêtre commun." << endl;
	}
	return false;

}

/*
* Fonction récursive pour trouver un ancêtre commun à partir de deux arbres donnés
* @param _premier : l’arbre qui sera inspecter noeud par noeud.
* @param _second : l’arbre qui sera parcouru à chaque recherche.
* @returns un nombre négatif dans le cas où il n’y a pas d’ancêtre commun
* sinon l’id de l’ancêtre commun
*/
template<class T>
short int Population<T>::aideAncetreCommun(Arbre<T>& _premier, Arbre<T>& _second) {
	// Vérifier que l’arbre ne soit pas vide premièrement
	if (_premier.estVide()) return -1;

	// Chercher l’id dans le second arbre
	if (_second.recherche(_premier.racine->getID()) < 0) {
		// Si non trouvé

		short int estGauche = -1, estDroit =-1;
		// On cherche avec l’ancêtre gauche
		if (_premier.racine->ancGauche != nullptr) {
			// On récupère l’ancêtre de gauche
			if (trouver(_premier.racine->ancGauche->getID())) {
				Arbre<T>& gauche = valeurCourante()->arbre;
				// On cherche à gauche
				estGauche = aideAncetreCommun(gauche, _second);
			}
		}

		// Puis si on ne l’a pas trouvé à gauche, on cherche avec l’ancêtre droit.
		if (_premier.racine->ancDroit != nullptr && estGauche < 0) {
			// On récupère l’ancêtre de droit
			if (trouver(_premier.racine->ancDroit->getID())) {
				Arbre<T>& droit = valeurCourante()->arbre;
				// On cherche à droite
				estDroit = aideAncetreCommun(droit, _second);
				// Peu importe le résultat, après avoir cherché à droite, on arrête la recherche
				return estDroit;
			}
		}
		// Si on a trouvé à gauche
		return estGauche; 

	// On a trouvé un résultat 
	} else {
		return _premier.racine->getID();
	}
}

// TO DO //////////////////////////////////////////////////////////////////////////////////////////
/*
* Fonction permettant d’afficher l’enfant commun de deux individus
* @param _premierID : l’id du premier individu
* @param _secondID : l’id du second individu
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