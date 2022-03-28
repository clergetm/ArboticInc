#pragma once
#include <string>
#include <iostream>
#include "Population.h"
#include "ColorCell.h"
using namespace std;

class Arbotic
{
private:

	Population<ColorCell> population;

public:


	void ouverture_transactions(string);
	void sauvegarde_population(string);





};