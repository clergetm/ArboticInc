#include "Noeud.h"



// Constructeur de Noeud
template<class T>
Noeud<T>::Noeud() {
	ancGauche = ancDroit = nullptr;
}

// Destructeur de Noeud
template<class T>
Noeud<T>::~Noeud() {
	delete ancGauche;
	delete ancDroie;
}

// Getter de ancGauche
template<class T>
Noeud<T>* Noeud<T>::GetancGauche() const { return gauche; }

// Getter de ancDroit
template<class T>
Noeud<T>* Noeud<T>::GetancDroit() const { return droit; }

// Getter de Cellule
template<class T>
T Noeud<T>::GetCellule() const { return cell; }

/**
* Setter de cellule
* @param _cellule: une cellule ColorCell ou ChromoCell
*/
template<class T>
void Noeud<T>::SetCellule(T _cellule){ cell = _cellule; }

// Return True si le Noeud est une feuille
template<class T> 
bool Noeud<T>::EstUneFeuille() const {	return (ancGauche == nullptr) && (ancDroit == nullptr) }