#pragma once

#include <string>
using namespace std;
class ColorCell
{
private:
	short int rouge;
	short int vert;
	short int bleu;

public:
	short int GetRouge() const;
	short int GetVert() const;
	short int GetBleu() const;

	void SetRouge(short int);
	void SetVert(short int);
	void SetBleu(short int);

	string ToString() const;
};

