#pragma once
#include <string>
#include "Arbre.h"
using namespace std;

template<class T>
class NoeudPop {
public:
	Arbre<T> arbre;
	NoeudPop<T>* suivant;
	
	/*
	* Constructeur de NoeudPop
	* @param _arbre : L’élément de ce noeud, sa valeur
	* @param _suiv : le pointeur suivant
	*/
	NoeudPop(const Arbre<T>& _arbre, NoeudPop<T>* _suiv = nullptr) {
		arbre = _arbre;
		suivant = _suiv;
	}
	
	/*
	* Constructeur de NoeudPop
	* @param _suiv : le pointeur suivant
	*/
	NoeudPop(NoeudPop<T>* _suiv = nullptr) { suivant = _suiv; }

	// Destructeur de NoeudPop
	~NoeudPop() {}
};
