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

	// GETTERS SETTERS ////////////////////////////////////////////////////////////////////////////////

	/*
	* Getter de l’ID de la racine.
	* Getter permettant simplement une meilleure lisibilité du code pour Population.
	* @returns l’id de la racine de l’arbre.
	*/
	short int getR_ID() { return arbre.getR_ID(); }

	/*
	* Getter de l’ancêtre gauche de la racine.
	* Getter permettant simplement une meilleure lisibilité du code pour Population.
	* @returns le noeud ancêtre gauche de l’arbre.
	*/
	Noeud<T>* getR() { return arbre.racine; }

	/*
	* Getter de l’ancêtre gauche de la racine.
	* Getter permettant simplement une meilleure lisibilité du code pour Population.
	* @returns le noeud ancêtre gauche de l’arbre.
	*/
	Noeud<T>* getR_Anc_Gauche() { return arbre.getR_Anc_Gauche(); }

	/*
	* Getter de l’ancêtre droit de la racine.
	* Getter permettant simplement une meilleure lisibilité du code pour Population.
	* @returns : le noeud ancêtre droit de l’arbre.
	*/
	Noeud<T>* getR_Anc_Droit() { return arbre.getR_Anc_Droit(); }

	/*
	* Getter de la cellule de la racine.
	* Getter permettant simplement une meilleure lisibilité du code pour Population.
	* @returns : la cellule de la racine de l’arbre.
	*/
	T getR_cell() { return arbre.getR_cell(); }

};
