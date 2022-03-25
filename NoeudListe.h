#pragma once
template < class T >
class NoeudListe
{
public:
	Arbre<T> element;
	NoeudListe* suivant;
	NoeudListe(const T & info, NoeudListe* suiv = NULL) // constructeur1
	{
		element = info;
		suivant = suiv;
	}

	NoeudListe(NoeudListe* suiv = NULL) // constructeur 2
	{
		suivant = suiv;
	}
	~NoeudListe()
	{
	}
};

