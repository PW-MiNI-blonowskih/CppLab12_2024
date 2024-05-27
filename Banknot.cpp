#include "Banknot.h"

Banknot::Banknot(std::string kraj, std::string nominal, int rok, int cena):
	kraj{kraj}, nominal{nominal}, rok{rok}, cena{cena}
{}

std::string Banknot::pobierz_nominal() const { return nominal; }
std::string Banknot::pobierz_kraj() const { return kraj; }
int Banknot::pobierz_cene()	const { return cena; }	
int Banknot::pobierz_rok() const { return rok; }

bool operator==(const Banknot& k1, const Banknot& k2)
{
	return ((k1.kraj == k2.kraj) && (k1.nominal == k2.nominal) && (k1.rok == k2.rok));
}

std::ostream& operator<<(std::ostream& out, const Banknot& k)
{
	out << "Kraj: " << k.kraj << ", Nominal: " << k.nominal << ", Rok: " << k.rok << ", Cena: " << k.cena;
	return out;
}

istream& operator>>(istream& in, Banknot& k)
{
	in >> k.kraj >> k.nominal >> k.rok >> k.cena;
	return in;
}