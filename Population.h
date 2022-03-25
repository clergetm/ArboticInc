#pragma once
#include <string>
#include "Noeud.h"

using namespace std;

template<class T>
class Population
{
public :
	Population(); // Constructeur
	~Population(); // Destructeur
	void ViderListe(); //Vide la liste
	void InsererFin();
	T Supprimer();
	void FixerTete();
	void Precedent();
	void Suivant();
	void EstDansListe();

private :
	NoeudListeColorCell<T>* Tete;
	Noeud<T>* fin;
	Noeud<T>* Courant;

};

template <class T>
Population<T>::Population() // Constructeur
{
	fin = Tete = courant = new Noeud<T>;
}

template <class T>
Population<T>::~Population() // Destructeur
{
	while (Tete != NULL)
}
