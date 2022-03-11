#pragma once

template<class T>
class Noeud {
public:
	T cell;
	Noeud<T>* ancGauche;
	Noeud<T>* ancDroit;
	short int id;

	Noeud<T>();
	~Noeud<T>();
	Noeud<T>* GetancGauche() const;
	Noeud<T>* GetancDroit() const;
	T GetCellule() const;
	void SetCellule(T);
	bool EstUneFeuille() const;
};
    