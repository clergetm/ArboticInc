#pragma once
#include <string>
#include "Arbre.h"
using namespace std;

template<class T>
class NoeudPop {
public:
	Arbre<T> arbre;					// L’élément du noeud.
	NoeudPop<T>* suivant;			// Le lien avec le prochain Noeud.
	
	// CONSTRUCTEURS DESTRUCTEURS ////////////////////////////////////////////////////////////////////

	/*
	* Constructeur de NoeudPop.
	* @param _arbre :	L’élément de ce noeud, sa valeur.
	* @param _suiv :	le pointeur suivant.
	*/
	NoeudPop(const Arbre<T>& _arbre, NoeudPop<T>* _suiv = nullptr) {
		arbre = _arbre;
		suivant = _suiv;
	}
	
	/*
	* Constructeur de NoeudPop.
	* @param _suiv : le pointeur suivant.
	*/
	NoeudPop(NoeudPop<T>* _suiv = nullptr) { suivant = _suiv; }

	// Destructeur de NoeudPop.
	~NoeudPop() {}

	short int getR_ID();												// Obtenir l’ID de la racine.
	Noeud<T>* getR();													// Obtenir la racine.
	Noeud<T>* getR_Anc_Gauche();										// Obtenir l’ancêtre gauche de la racine.
	Noeud<T>* getR_Anc_Droit();											// Obtenir l’ancêtre droite de la racine.
	T getR_cell();														// Obtenir la cellule de la racine.
	
};

// GETTERS SETTERS ////////////////////////////////////////////////////////////////////////////////

/*
* Getter de l’ID de la racine.
* Getter permettant simplement une meilleure lisibilité du code pour Population.
* @returns l’id de la racine de l’arbre.
*/
template<class T>
short int NoeudPop<T>::getR_ID() { return arbre.getR_ID(); }

/*
* Getter de l’ancêtre gauche de la racine.
* Getter permettant simplement une meilleure lisibilité du code pour Population.
* @returns le noeud ancêtre gauche de l’arbre.
*/
template<class T>
Noeud<T>* NoeudPop<T>::getR() { return arbre.racine; }

/*
* Getter de l’ancêtre gauche de la racine.
* Getter permettant simplement une meilleure lisibilité du code pour Population.
* @returns le noeud ancêtre gauche de l’arbre.
*/
template<class T>
Noeud<T>* NoeudPop<T>::getR_Anc_Gauche() { return arbre.getR_Anc_Gauche(); }

/*
* Getter de l’ancêtre droit de la racine.
* Getter permettant simplement une meilleure lisibilité du code pour Population.
* @returns : le noeud ancêtre droit de l’arbre.
*/
template<class T>
Noeud<T>* NoeudPop<T>::getR_Anc_Droit() { return arbre.getR_Anc_Droit(); }

/*
* Getter de la cellule de la racine.
* Getter permettant simplement une meilleure lisibilité du code pour Population.
* @returns : la cellule de la racine de l’arbre.
*/
template<class T>
T NoeudPop<T>::getR_cell() { return arbre.getR_cell(); }

// FONCTIONS //////////////////////////////////////////////////////////////////////////////////////


/*
* Surcharge de l’opérateur <<. Retour du toString du NoeudPop.
* @param _out :			le stream de output.
* @param _noeud :		le NoeudPop à représenter.
* @returns				le stream à jour.
*/
template<class T>
ostream& operator<< (ostream& _out, NoeudPop<T>* _noeud) {

	Noeud<T>* racine = _noeud->getR();
	_out << to_string(racine->getID()) + " ";

	if (racine->ancGauche != nullptr) {
		// res : 3_1_
		_out << to_string(racine->ancGauche->getID()) + " ";
	}
	else
	{
		// res : 3_/_
		_out << "/ ";
	}

	if (racine->ancGauche != nullptr) {
		// res : 3_1_2_
		_out << to_string(racine->ancGauche->getID()) + " ";
	}
	else
	{
		// res : 3_1_/_
		_out << "/ ";
	}

	// res : 3_1_2_127_127_127
	T cell = racine->cell;
	_out << cell;
	return _out;
}
