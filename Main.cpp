#include <iostream>

#include "Noeud.h"
#include "ColorCell.h"
#include "Arbre.h"
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

void test_To_String() {
	ColorCell A = ColorCell(255, 255, 255);
	ColorCell B = ColorCell(127, 127, 127);
	ColorCell C = ColorCell(0, 0, 0);
	
	Arbre<ColorCell> arbre;
	arbre.racine = new Noeud<ColorCell>(2, B);
	arbre.racine->ancGauche = new Noeud<ColorCell>(1, A);
	arbre.racine->ancDroit = new Noeud<ColorCell>(3, C);

	cout << arbre.toString(arbre.racine, 0) << endl;
}

void test_Operator_Plus() {
	ColorCell A = ColorCell(255, 255, 255);
	cout << " A = " << A.toString() << endl;
	ColorCell C = ColorCell(0, 0, 0);
	cout << " C = " << C.toString() << endl;
	ColorCell B = A + C;
	cout << "A+C= " << B.toString() << endl;
}
int main() {
	
	test_Operator_Plus();

	system("pause");
	return 0;
}