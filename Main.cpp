#include <iostream>
#include "Banknot.h"
#include "Kolekcja.h"
using namespace std;

int main()
{
	cout << endl;
	cout << "*********************** ETAP 1 (1.0 pkt) *********************** " << endl << endl;

	Banknot b1("Polska", "20 zl", 1936, 12);
	Banknot b2("Polska", "5 gr", 1924, 150);
	Banknot b3("Polska", "20 zl", 1936, 33);
	Banknot b4("Polska", "250000 marek", 1923, 500);

	cout << "Banknot 1: " << b1 << endl << "Banknot 2: " << b2 << endl << "Banknot 3: " << b3 << endl << "Banknot 4: " << b4 << endl << endl;
	if (b1 == b3) cout << "Banknoty 1 i 3 sa takie same" << endl << endl;
	else cout << "Blad operatora" << endl << endl;


	cout << "*********************** ETAP 2 (2.0 pkt) *********************** " << endl << endl;

	Banknot b5("Rosja", "100 rubli", 1910, 75);
	Banknot b6("Rosja", "500 rubli", 1912, 400);
	Kolekcja kol_pol;
	Kolekcja kol_rus;
	cout << kol_pol << endl;
	kol_pol.dodaj(b1);
	kol_pol.dodaj(b2);
	kol_pol.dodaj(b3);
	kol_pol.dodaj(b4);
	cout << "Kolekcja banknotow Polski miedzywojennej:" << endl;
	cout << kol_pol;
	cout << "Wartosc kolekcji: " << kol_pol.wartosc_kolekcji() << " zl" << endl << endl;
	cout << "Kolekcja banknotow Rosji carskiej:" << endl;
	kol_rus.dodaj(b5);
	kol_rus.dodaj(b6);
	cout << kol_rus;
	cout << "Wartosc kolekcji: " << kol_rus.wartosc_kolekcji() << " zl" << endl << endl;

	cout << "*********************** ETAP 3 (3.0 pkt) *********************** " << endl << endl;

	cout << "Wyrzucamy z kolekcji polskiej najtansze" << endl;
	Kolekcja kol_usunietych;
	list<Banknot> temp = kol_pol.znajdz_w_kolekcji(40);
	kol_usunietych.dodaj(temp);
	if (!temp.empty()) { cout << "Lista niewyczyszczona" << endl;  system("pause"); return 1; }
	cout << "Kolekcja banknotow usunietych:" << endl;
	cout << kol_usunietych;
	cout << "Wartosc kolekcji: " << kol_usunietych.wartosc_kolekcji() << " zl" << endl << endl;
	kol_pol.usun_z_kolekcji(40);
	cout << "Kolekcja polska po modyfikacji:" << endl;
	cout << kol_pol;
	cout << "Wartosc kolekcji: " << kol_pol.wartosc_kolekcji() << " zl" << endl << endl;
	cout << "Do kolekcji polskiej dolaczamy kolekcje banknotow Rosji carskiej:" << endl;
	kol_pol.dodaj(kol_rus);
	cout << "Kolekcja banknotow po modyfikacji:" << endl;
	cout << kol_pol;
	cout << "Wartosc kolekcji: " << kol_pol.wartosc_kolekcji() << " zl" << endl << endl;
	if (!kol_rus.czy_pusta()) { cout << "Kolekcja niewyczyszczona" << endl;  system("pause"); return 1; }

	cout << "*********************** ETAP 4 (2.0 pkt) *********************** " << endl << endl;

	Kolekcja kol_z_pliku;
	kol_z_pliku.wczytaj("kolekcja.txt");
	cout << "Kolekcja wczytana z pliku:" << endl;
	cout << kol_z_pliku;
	cout << "Wartosc kolekcji: " << kol_z_pliku.wartosc_kolekcji() << " zl" << endl << endl;

	cout << "*********************** ETAP 5 (2.0 pkt) *********************** " << endl << endl;

	kol_z_pliku.sortowanie();
	cout << "Kolekcja posortowana w/g ceny:" << endl;
	cout << kol_z_pliku;
	cout << "Wartosc kolekcji: " << kol_z_pliku.wartosc_kolekcji() << " zl" << endl << endl;

	system("pause");
	return 0;
}