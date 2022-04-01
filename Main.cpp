#include <iostream>

#include <fstream>
#include "Noeud.h"
#include "ColorCell.h"
#include "ChromoCell.h"
#include "Arbre.h"
#include "Population.h"
#include "Arbotic.h"

using namespace std;

void test_Noeud_Template() {

	cout << "Test int" << endl;
	Noeud<int> testInt = Noeud<int>(1, 30);
	cout << "ID : " << testInt.getID() << " ";
	cout << "valeur " << testInt.cell << endl;

	cout << "Test ColorCell" << endl;
	ColorCell cell = ColorCell(255, 255, 255);
	Noeud<ColorCell> testCell = Noeud<ColorCell>(2, cell);
	cout << testCell.toString() << endl;


}

void test_toString() {
	cout << "Test toString" << endl;
	ColorCell A = ColorCell(255, 255, 255);
	ColorCell B = ColorCell(127, 127, 127);
	ColorCell C = ColorCell(0, 0, 0);

	Arbre<ColorCell> arbre;
	arbre.racine = new Noeud<ColorCell>(2, B);
	arbre.racine->ancGauche = new Noeud<ColorCell>(1, A);
	arbre.racine->ancDroite = new Noeud<ColorCell>(3, C);

	cout << arbre.toString() << endl;
}

void test_Operator_Plus() {
	cout << "Test surcharge +" << endl;
	ColorCell A = ColorCell(255, 255, 255);
	cout << " A = " << A.toString() << endl;
	ColorCell C = ColorCell(0, 0, 0);
	cout << " C = " << C.toString() << endl;
	ColorCell B = A + C;
	cout << "A+C= " << B.toString() << endl;
}

void test_C() {
	cout << "Test fichier et surcharges << >>" << endl;

	ifstream f("TestColor.txt");

	ColorCell c = ColorCell();
	f >> c;
	cout << c;
}

void test_recherche() {
	cout << "Test recherche" << endl;

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
	NB->ancDroite = NE;
	auto NC = new Noeud<ColorCell>(3, C);
	auto NF = new Noeud<ColorCell>(6, F);
	NC->ancGauche = ND;
	NC->ancDroite = NF;

	arbre.racine->ancGauche = NB;
	arbre.racine->ancDroite = NC;

	cout << arbre.toString() << endl;
	cout << "resultat recherche : " << arbre.recherche(4) << endl;
	cout << "resultat recherche : " << arbre.recherche(2) << endl;
	cout << "resultat recherche : " << arbre.recherche(1) << endl;
	cout << "resultat recherche : " << arbre.recherche(60) << endl;
}

void test_ancetreCommun() {
	cout << "Test ancetreCommun" << endl;
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
	NA->ancDroite = NC;
	NB->ancGauche = ND;
	NB->ancDroite = NE;
	NC->ancGauche = ND;
	NC->ancDroite = NF;


	Population<ColorCell> pop;
	pop.insererFin(NA);
	pop.insererFin(NB);
	pop.insererFin(NC);
	pop.insererFin(ND);
	pop.insererFin(NE);
	pop.insererFin(NF);

	cout << pop.ancetreCommun(2, 3) << endl;

	pop.supprimer(1);
	cout << pop.ancetreCommun(2, 4) << endl;
}

void test_enfantCommun() {
	cout << "Test enfantCommun" << endl;
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
	NA->ancDroite = NC;
	NB->ancGauche = ND;
	NB->ancDroite = NE;
	NC->ancGauche = ND;
	NC->ancDroite = NF;
	ND->ancGauche = NE;
	ND->ancDroite = NF;

	Population<ColorCell> pop;
	//pop.insererFin(Arbre<ColorCell>(NA));
	pop.insererFin(NB);
	pop.insererFin(NC);
	pop.insererFin(ND);
	pop.insererFin(NE);
	pop.insererFin(NF);

	short int* info = pop.enfantCommun(4, 5);
	cout << "enfant = " << *info << endl;
	cout << "diff génération = " << *(info + 1) << endl;

}

void test_ancetreETenfant() {
	cout << "Test ancetreETenfant" << endl;
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
	NA->ancDroite = NC;
	NB->ancGauche = ND;
	NB->ancDroite = NE;
	NC->ancGauche = ND;
	NC->ancDroite = NF;
	ND->ancGauche = NE;
	ND->ancDroite = NF;

	Population<ColorCell> pop;
	pop.insererFin(NA);
	pop.insererFin(NB);
	pop.insererFin(NC);
	pop.insererFin(ND);
	pop.insererFin(NE);
	pop.insererFin(NF);

	cout << pop.toStringIndividu(1);
	pop.ancetreETenfantCommuns(1, 2);

	cout << "suppression de 1" << endl;
	pop.supprimer(1);
	pop.ancetreETenfantCommuns(2, 3);
}

void test_supprimer() {
	cout << "Test supprimer" << endl;
	ColorCell A = ColorCell(255, 255, 255);
	ColorCell B = ColorCell(127, 127, 127);
	ColorCell C = ColorCell(0, 0, 0);
	ColorCell D = ColorCell(0, 0, 0);
	ColorCell E = ColorCell(0, 0, 0);

	auto NA = new Noeud<ColorCell>(1, A);
	auto NB = new Noeud<ColorCell>(2, B);
	auto NC = new Noeud<ColorCell>(3, C);
	auto ND = new Noeud<ColorCell>(4, D);
	auto NE = new Noeud<ColorCell>(5, E);


	NA->ancGauche = NB;
	NA->ancDroite = NC;
	NB->ancGauche = ND;
	NB->ancDroite = NE;

	Population<ColorCell> pop;
	pop.insererFin(NA);
	pop.insererFin(NB);
	pop.insererFin(NC);
	pop.insererFin(ND);
	pop.insererFin(NE);

	cout << pop.toStringIndividu(1) << endl;

	cout << "suppression de 4" << endl;
	pop.supprimer(4);
	cout << pop.toStringIndividu(1) << endl;


	cout << "suppression de 1" << endl;
	pop.supprimer(1);
	cout << pop.toStringIndividu(1) << endl;

	pop.supprimer(1);
}

void test_generer() {
	cout << "Test generer" << endl;
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
	NA->ancDroite = NC;
	NB->ancGauche = ND;
	NB->ancDroite = NE;
	NC->ancGauche = ND;
	NC->ancDroite = NF;
	ND->ancGauche = NE;
	ND->ancDroite = NF;

	Population<ColorCell> pop;
	pop.insererFin(NA);
	pop.insererFin(NB);
	pop.insererFin(NC);
	pop.insererFin(ND);
	pop.insererFin(NE);
	pop.insererFin(NF);
	for (int i = 0; i < 5; i++) pop.getNextID();

	pop.generer(4);
	for (pop.fixerTete(); pop.estDansListe(); pop.suivant()) {
		cout << pop.valeurCourante()->arbre.toString() << endl;
	}
}

void test_chromocell() {
	cout << "Test chromocell" << endl;

	char paire[2];
	paire[0] = 'A';
	paire[1] = 'B';
	char paire2[2];
	paire2[0] = 'C';
	paire2[1] = 'D';
	char paire3[2];
	paire3[0] = 'E';
	paire3[1] = 'F';
	char paire4[2];
	paire4[0] = 'G';
	paire4[1] = 'H';
	ChromoCell cell = ChromoCell(paire, paire2, paire3, paire4);
	cout << cell.toString() << endl;


	ChromoCell cell2 = ChromoCell();
	cin >> cell2;

	cout << cell2.toString() << endl;

	ChromoCell cell3 = cell + cell2;
	cout << cell3.toString() << endl;

}

int main() {
	setlocale(LC_CTYPE, "fr-FR");
	//test_Noeud_Template();
	//test_toString();
	//test_Operator_Plus();
	//test_C();
	//test_recherche();
	//test_ancetreCommun();
	//test_enfantCommun();
	//test_ancetreETenfant();
	//test_supprimer();
	//test_generer();
	//test_chromocell();
	const string PATH = "Fichiers/";
	const string T_COLORCELL = PATH + "TRANSACTION_COLORCELL.txt";
	const string T_CHROMOCELL = PATH + "TRANSACTION_CHROMOCELL.txt";
	const string T_MIXTE = PATH + "TRANSACTION_MIXTE.txt";

	Arbotic arbotic;
	srand(5);
	//cout << "\n\n\n" << "T_COLORCELL" << "\n\n\n";
	//arbotic.O_transactions(T_COLORCELL);
	//cout << "\n\n\n" << "T_CHROMOCELL" << "\n\n\n";
	//arbotic.O_transactions(T_CHROMOCELL);
	cout << "\n\n\n" << "T_MIXTE" << "\n\n\n";
	arbotic.O_transactions(T_MIXTE);

	system("pause");
	return 0;
}
