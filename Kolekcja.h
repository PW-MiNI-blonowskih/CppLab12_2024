#pragma once
#include <iostream>
#include <list>
#include "Banknot.h"
using namespace std;

class Kolekcja
{
	list<Banknot> banknoty;
public:
	//Etap 2
	Kolekcja() {};
	void dodaj(Banknot);
	int wartosc_kolekcji();
	int wielkosc_kolekcji() { return banknoty.size(); }
	bool czy_pusta() const { return banknoty.empty(); }
	friend ostream& operator<<(ostream& out, const Kolekcja& k);

	//Etap 3
	list<Banknot> znajdz_w_kolekcji(int cena);
	void usun_z_kolekcji(int cena);
	void dodaj(list<Banknot> &banknoty);
	void dodaj(Kolekcja &kol);	

	//Etap 4
	void wczytaj(const char*);

	//Etap 5
	void sortowanie();
	
};

//Etap 3
//Funktor - todo
