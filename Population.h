#pragma once
#include <string>
#include "Noeud.h"
#include "NoeudListe.h"
#include <cassert>

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
	bool EstDansListe() const;

private :
	NoeudListe<T>* tete;
	NoeudListe<T>* queue;
	NoeudListe<T>* courant;

};

template <class T>
Population<T>::Population() // Constructeur
{
	queue = tete = courant = new NoeudListe<T>;
}


template <class T>
Population<T>::~Population() // Destructeur
{
	while (tete != NULL)
	{
		courant = tete->suivant;
		tete->suivant = courant->suivant;
		delete courant;
	}
	courant = queue = tete; //réinitialise
}


template <class T>
void Population<T>::ViderListe()
{
	// libère l'espace alloué aux noeuds, garde l'entête.
	while (tete->suivant != NULL)
	{
		courant = tete->suivant;
		tete->suivant = courant->suivant;
		delete courant;
	}
	courant = queue = tete; // réinitialise
}

template <class T>
T Population<T>::Supprimer() // supprime et retourne l'élément courant
{
	assert(EstDansListe()); // Courant doit être une position valide
	T temp = courant->suivant->element; //Sauvegarde de l'élément courant
	NoeudList<T>* ptemp = courant->suivant; // Sauvegarde du pointeur du noeud Courant
	courant->suivant = ptemp->Suivant; // suppression de l'élément
	if (queue == ptemp)
		queue = courant; // C'est le dernier élément supprimé, mise à jour de Fin
	delete ptemp;
	return temp;
}

template <class T>
void Population<T>::FixerTete() // rend la tête comme position courante
{
	courant = tete;
}

template <class T>
void Population<T>::Precedent() // met la position courante à la position précédente
{
	Noeud<T>* temp = tete;
	if ((courant == NULL) || (courant == tete)) // pas d'élément précédent
	{
		courant = NULL;
		return;
	}
	while ((temp != NULL) && (temp->Suivant != courant))
		temp = temp->Suivant;
	courant = temp;
}

template <class T>
void Population<T>::Suivant()
{
	if (courant != NULL)
		courant = courant->suivant;
}

template <class T>
bool Population<T>::EstDansListe() const
{
	return (courant != NULL) && (courant->suivant != NULL);
}