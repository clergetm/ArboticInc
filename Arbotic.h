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

public:
	void ouverture_transactions(string _fichierTransaction);
	Population<ColorCell> O_colorPop(string);
	Population<ChromoCell> O_chromoPop(string);
	void S_colorPop(string, Population<ColorCell>&);
	void S_chromoPop(string, Population<ChromoCell>&);
};

