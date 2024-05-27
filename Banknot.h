#pragma once
#include <iostream>
using namespace std;

class Banknot
{
	int cena;
	int rok;
	string nominal;
	string kraj;
public:
	//Etap 1
	Banknot() {};
	Banknot(string kraj, string nominal, int rok, int cena);
	string pobierz_nominal() const;
	string pobierz_kraj() const;
	int pobierz_rok() const;
	int pobierz_cene() const;
	friend bool operator==(const Banknot& k1, const Banknot& k2);
	friend ostream& operator<<(ostream& out, const Banknot& k);

	//Etap 4
	friend istream& operator>>(istream& in, Banknot& k);
};