#pragma once
#include "Noeud.h"
#include <string>
using namespace std;

template<class T>
class Arbre
{
public:
	Noeud<T>* racine;													// Le noeud racine de l’arbre

	Arbre();															// Constructeur par défaut
	~Arbre();															// Destructeur par défaut
	bool estVide() const;												// Fonction vérifiant si l’arbre est vide
	void viderArbre();													// Fonction initiant la suppression de l’arbre
	void aideVider(Noeud<T>*);											// Fonction récursive pour vider l’arbre

	short int recherche(const short int& _id);							// Fonction initiant la recherche
	bool aideRecherche(Noeud<T>*, const short int&, short int&);		// Fonction récursive de recherche
	string toString(Noeud<T>*, short int);								// Représentation textuelle de l’arbre
};

// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////////

// Constructeur par défaut
template<class T>
Arbre<T>::Arbre() { racine = nullptr; }


template<class T>
Arbre<T>::~Arbre() { viderArbre(); }

// GETTERS SETTERS ////////////////////////////////////////////////////////////////////////////////

// FONCTIONS //////////////////////////////////////////////////////////////////////////////////////

// Retourne True si l'arbre est vide
template <class T>
bool Arbre<T>::estVide() const { return racine == nullptr; }

/**
* Fonction récursive pour vider l'arbre
* Vider l'arbre à partir d'un noeud donné
* @param _racine : un noeud de l'arbre
*/
template<class T>
void Arbre<T>::aideVider(Noeud<T>* _racine) {

	// La racine est vide
	//if (_racine == nullptr) {
	//	cout << "La racine est déjà vide." << endl;
	//	return;
	//}
	//aideVider(_racine->ancGauche);
	//aideVider(_racine->ancDroit);
	//if (_racine != racine) {
	//	cout << _racine->getID() << endl;
	//	delete _racine;
	//}
}

// Vider l'arbre
template<class T>
void Arbre<T>::viderArbre() {
	aideVider(racine);
	racine = nullptr;
}

/**
* Fonction récursif pour retourner l'affichage de l'arbre
* Retourner l'affichage l'arbre à partir d'un noeud donné et d'une génération donnée 
* @param _racine : le noeud de départ
* @param _generation : le nombre de tiret au lancement de la fonction
*/
template<class T>
string Arbre<T>::toString(Noeud<T>* _racine,short int _generation) {
	string res = "";
	if (_racine != nullptr) {
		// Obtenir les valeurs de la cellule de ce Noeud
		res += string(_generation, '-') + _racine->toString()+'\n';
		_generation++;
		
		// Obtenir les valeurs de la cellule de l'ancêtre Gauche
		res += toString(_racine->ancGauche, _generation);

		// Obtenir les valeurs de la cellule de l'ancêtre Droit
		res += toString(_racine->ancDroit, _generation);
	}
	return res;
}

/*
* Fonction récursif de recherche avec parcours préfixe d’arbre
* @param _racine : le noeud courant
* @param _id : l’id recherché
* @param _generation : la génération courante
* @param true si l’id recherché est trouvé, 
* la géneration est modifiée en conséquence du résultat de la recherche : 
* - La génération où se trouve l’id trouvé.
* - un short int négatif si la recherche échoue
*/
template<class T>
bool Arbre<T>::aideRecherche(Noeud<T>* _racine, const short int& _id, short int& _generation) {
	// Si ce noeud possède le bon id :
	if (_racine == nullptr) return false; // Si on arrive à une feuille, on annule la recherche
	if (_racine->getID() == _id) return true; // Si on arrive à l’ID recherché, on valide la recherche

	// Sinon on visite ses ancêtres :
	_generation++; // visiter les ancêtres signifie changer de génération
	bool isGauche = aideRecherche(_racine->ancGauche,_id,_generation); // On cherche du côté gauche

	// S’il n’est pas du côté gauche
	if (!isGauche) {
		// On cherche du côté droit
		bool isDroit = aideRecherche(_racine->ancDroit, _id, _generation);
		// On renvoit le résultat du côté droit 
		return isDroit;
	}
	// Si l’ID est du côté gauche, on renvoit true
	else return isGauche;
}

/*
* Fonction de recherche dans l’arbre de l’id en paramètre
* @param _id : l’id recherché
* @returns generation : un nombre positif correspond à la génération où se trouve l’id recherché dans l’arbre
* un nombre négatif dans le cas d’échec de la recherche
*/
template<class T>
short int Arbre<T>::recherche(const short int& _id) {
	// La recherche depuis la racine signifie la génération actuelle, donc 0
	short int generation = 0;
	// Si un résultat est trouvé on renvoit la génération correspondante
	if (aideRecherche(racine, _id, generation)) {
		return generation;
	} else {
		// Sinon on renvoit un short int négatif indiquant l’échec de la recherche 
		return -1;
	}
}