#pragma once
#include <string>
#include <iostream>
#include "Population.h"
#include "ColorCell.h"
#include "ChromoCell.h"
using namespace std;

class Arbotic
{
private:
	const string PATH = "Fichiers/";
	
	string currentCell;
	Population<ColorCell> colorPop;
	Population<ChromoCell> chromoPop;
public:
	Arbotic();
	~Arbotic();
	void O_transactions(string _fichierTransaction);
	void O_colorPop(string);
	void O_chromoPop(string);
	void S_colorPop(string);
	void S_chromoPop(string);

	Population<ColorCell>& newColorPop() { Population<ColorCell> colorPop; return colorPop; }
};

