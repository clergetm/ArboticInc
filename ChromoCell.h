#pragma once
#include <string>
#include <iostream>
using namespace std;

class ChromoCell
{
private:
	char paireUne[2];
	char paireDeux[2];
	char paireTrois[2];
	char paireQuatre[2];

public:
	ChromoCell();
	ChromoCell(char, char, char, char);
	~ChromoCell();

	char getPaireUne() const;
	char getPaireDeux() const;
	char getPaireTrois() const;
	char getPaireQuatre() const;

	void setPaireUne(char);
	void setPaireDeux(char);
	void setPaireTrois(char);
	void setPaireQuatre(char);

	string toString() const;

	ChromoCell operator + (ChromoCell c);
	friend istream& operator>> (istream& in, ChromoCell& chromocell);
	friend ostream& operator<< (ostream& out, ChromoCell& chromocell);


};
