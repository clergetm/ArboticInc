#pragma once
#include <string>
using namespace std;

template<class T>
class Noeud {
private:
	short int id;					// READ-ONLY.
public:
	T cell;							// Valeur du Noeud.
	Noeud<T>* ancGauche;			// Ancêtre de Gauche.
	Noeud<T>* ancDroite;			// Ancêtre de Droite.

	Noeud<T>(short int, T);			// Constructeur complet, id et valeur.
	Noeud<T>(short int);			// Constructeur avec id.
	~Noeud<T>();					// Destructeur.
	
	short int getID() const;		// Getter ID.
	//Noeud<T>* getancGauche() const;	// Getter ancGauche.
	//Noeud<T>* getancDroit() const;	// Getter ancDroite.
	//T getCellule() const;			// Getter valeur.
	//
	//void setancGauche(Noeud<T>*);	// Getter ancGauche.
	//void setancDroit(Noeud<T>*);	// Getter ancDroite.
	//void setCellule(T);				// Setter valeur.
	
	bool estUneFeuille() const;		// Vérifier si le noeud est une feuille.
	string toString() const;		// Représentation textuelle du Noeud.
};
   
// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////////

/**
* Constructuer de Noeud avec id.
* @param _id:		identifiant du Noeud.
*/
template<class T>
Noeud<T>::Noeud(short int _id) {
	ancGauche = nullptr;
	ancDroite = nullptr;
	this->id = _id;
}

/**
* Constructuer de Noeud avec id et valeur.
* @param _id:		identifiant du Noeud.
* @param _valeur:	une cellule ColorCell ou ChromoCell.
*/
template<class T>
Noeud<T>::Noeud(short int _id, T _valeur) {
	ancGauche = nullptr;
	ancDroite = nullptr;
	this->id = _id;
	this->cell = _valeur;
}

// Destructeur de Noeud.
template<class T>
Noeud<T>::~Noeud() {
	delete ancGauche;
	delete ancDroite;
}

// GETTERS SETTERS ////////////////////////////////////////////////////////////////////////////////

// Getter de id.
template<class T>
short int Noeud<T>::getID() const { return this->id; }

//// Getter de ancGauche.
//template<class T>
//Noeud<T>* Noeud<T>::getancGauche() const { return this->ancGauche; }
//
//// Getter de ancDroite.
//template<class T>
//Noeud<T>* Noeud<T>::getancDroit() const { return this->ancDroite; }
//
//// Getter de Cellule.
//template<class T>
//T Noeud<T>::getCellule() const { return this->cell; }

///**
//* Setter de ancGauche.
//* @param _ancetre: un Noeud ancetre
//*/
//template<class T>
//void Noeud<T>::setancGauche(Noeud<T>* _ancetre){ this->ancGauche = _ancetre; }
//
///**
//* Setter de ancDroite.
//* @param _ancetre: un Noeud ancetre
//*/
//template<class T>
//void Noeud<T>::setancDroit(Noeud<T>* _ancetre) { this->ancDroite = _ancetre; }
//
///**
//* Setter de cellule.
//* @param _cellule: une cellule ColorCell ou ChromoCell
//*/
//template<class T>
//void Noeud<T>::setCellule(T _cellule) { this->cell = _cellule; }

// FONCTIONS //////////////////////////////////////////////////////////////////////////////////////

/** 
* Vérifie si le Noeud est une feuille.
* @returns true si c’est un noeud sans Ancêtre Gauche et Droite.
*/
template<class T>
bool Noeud<T>::estUneFeuille() const { return (this->ancGauche == nullptr) && (this->ancDroite == nullptr); }

/**
* Fonction toString du noeud.
* Le toString doit retourner un string de cette forme.
* Exemple :
* - A, B et C sont 3 noeuds.
* - A est une feuille avec une ColorCell	255	255	255	et ID 1.
* - B est une feuille avec une ColorCell	0	0	0	et ID 2.
* - C a comme ancêtres A (gauche) et B (droit)			et ID 3.
* - C->toString() retourne :
*				3 1 2 127 127 127
*/
template<class T>
string Noeud<T>::toString() const {
	// Suivi exemple avec _ pour les espaces
	// res : 3_
	string res = to_string(id) + " ";

	if (ancGauche != nullptr) {
		// res : 3_1_
		res += to_string(ancGauche->getID()) + " ";
	}
	else
	{
		// res : 3_/_
		res += "/ ";
	}

	if (ancDroite != nullptr) {
		// res : 3_1_2_
		res += to_string(ancDroite->getID()) + " ";
	}
	else
	{
		// res : 3_1_/_
		res += "/ ";
	}

	// res : 3_1_2_127_127_127
	res += this->cell.toString();
	return res;
}
