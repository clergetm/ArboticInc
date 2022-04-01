#pragma once
#include <string>
#include <iostream>
using namespace std;

class ChromoCell
{
private:
	string listChromo() const;
	bool pileOuFace() const;
public:
	char paireUne[2];
	char paireDeux[2];
	char paireTrois[2];
	char paireQuatre[2];

	ChromoCell();
	ChromoCell(char[], char[], char[], char[]);
	~ChromoCell();

	string toString() const;
	ChromoCell operator + (ChromoCell c);
	friend istream& operator>> (istream& in, ChromoCell& chromocell);
	friend ostream& operator<< (ostream& out, ChromoCell& chromocell);


};
