#include <iostream>

#include <fstream>
#include "Noeud.h"
#include "ColorCell.h"
#include "Arbre.h"
#include "Population.h"

using namespace std;

void test_Noeud_Template() {

	cout << "Test int" << endl;
	Noeud<int> testInt = Noeud<int>(1,30);
	cout << "ID : " << testInt.getID() << " ";
	cout << "valeur " << testInt.cell << endl;

	cout << "Test ColorCell" << endl;
	ColorCell cell = ColorCell(255, 255, 255);
	Noeud<ColorCell> testCell = Noeud<ColorCell>(2, cell);
	cout << testCell.toString() << endl;


}

void test_toString() {
	ColorCell A = ColorCell(255, 255, 255);
	ColorCell B = ColorCell(127, 127, 127);
	ColorCell C = ColorCell(0, 0, 0);
	
	Arbre<ColorCell> arbre;
	arbre.racine = new Noeud<ColorCell>(2, B);
	arbre.racine->ancGauche = new Noeud<ColorCell>(1, A);
	arbre.racine->ancDroit = new Noeud<ColorCell>(3, C);

	cout << arbre.toString() << endl;
}

void test_Operator_Plus() {
	ColorCell A = ColorCell(255, 255, 255);
	cout << " A = " << A.toString() << endl;
	ColorCell C = ColorCell(0, 0, 0);
	cout << " C = " << C.toString() << endl;
	ColorCell B = A + C;
	cout << "A+C= " << B.toString() << endl;
}

void test_C(){

	ifstream f("TestColor.txt");

	ColorCell c = ColorCell();
	f >> c;
	cout << c;
}

void test_Recherche() {
	/*
			A
		B		C
	  D   E   D   F
	*/
	ColorCell D = ColorCell(255, 255, 255);
	ColorCell F = ColorCell(127, 127, 127);
	ColorCell E = ColorCell(0, 0, 0);

	ColorCell B = D + E;
	ColorCell C = D + F;
	ColorCell A = B + C;
	
	Arbre<ColorCell> arbre;
	arbre.racine = new Noeud<ColorCell>(1, A);
	auto NB = new Noeud<ColorCell>(2, B);
	auto ND = new Noeud<ColorCell>(4, D);
	auto NE = new Noeud<ColorCell>(5, E);
	NB->ancGauche = ND;
	NB->ancDroit = NE;
	auto NC = new Noeud<ColorCell>(3, C);
	auto NF = new Noeud<ColorCell>(6, F);
	NC->ancGauche = ND;
	NC->ancDroit = NF;

	arbre.racine->ancGauche = NB;
	arbre.racine->ancDroit = NC;
	
	cout << arbre.toString() << endl;
	cout << "resultat recherche : " << arbre.recherche(4) << endl;
	cout << "resultat recherche : " << arbre.recherche(2) << endl;
	cout << "resultat recherche : " << arbre.recherche(1) << endl;
	cout << "resultat recherche : " << arbre.recherche(60) << endl;
}

void test_AncetreCommun() {
	ColorCell D = ColorCell(255, 255, 255);
	ColorCell F = ColorCell(127, 127, 127);
	ColorCell E = ColorCell(0, 0, 0);

	ColorCell B = D + E;
	ColorCell C = D + F;
	ColorCell A = B + C;

	auto NA = new Noeud<ColorCell>(1, A);
	auto NB = new Noeud<ColorCell>(2, B);
	auto NC = new Noeud<ColorCell>(3, C);
	auto ND = new Noeud<ColorCell>(4, D);
	auto NE = new Noeud<ColorCell>(5, E);
	auto NF = new Noeud<ColorCell>(6, F);

	NA->ancGauche = NB;
	NA->ancDroit = NC;
	NB->ancGauche = ND;
	NB->ancDroit = NE;
	NC->ancGauche = ND;
	NC->ancDroit = NF;
	

	Population<ColorCell> pop;
	pop.insererFin(Arbre<ColorCell>(NA));
	pop.insererFin(Arbre<ColorCell>(NB));
	pop.insererFin(Arbre<ColorCell>(NC));
	pop.insererFin(Arbre<ColorCell>(ND));
	pop.insererFin(Arbre<ColorCell>(NE));
	pop.insererFin(Arbre<ColorCell>(NF));
	
	pop.ancetreCommun(2, 3);
}
int main() {
	setlocale(LC_CTYPE, "fr-FR");
	test_Recherche();

	system("pause");
	return 0;
}
