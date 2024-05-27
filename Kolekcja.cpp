#include "Kolekcja.h"
#include <fstream>
#include <sstream>
#include <vector>

void Kolekcja::dodaj(Banknot k)
{
	banknoty.push_back(k);
}

std::ostream& operator<<(std::ostream& out, const Kolekcja& k)
{
	if (k.czy_pusta())
	{
		out << "Kolekcja pusta!\n";
		return out;
	}

	for (std::list<Banknot>::const_iterator it = k.banknoty.begin(); it != k.banknoty.end(); it++)
	{
		out << *it << std::endl;
	}
}

int Kolekcja::wartosc_kolekcji()
{
	int wartosc{ 0 };

	for (std::list<Banknot>::const_iterator it = banknoty.begin(); it != banknoty.end(); it++)
	{
		wartosc += (*it).pobierz_cene();
	}

	return wartosc;
}

std::list<Banknot> Kolekcja::znajdz_w_kolekcji(int cena)
{
	std::list<Banknot> lst;

	for (std::list<Banknot>::const_iterator it = banknoty.begin(); it != banknoty.end(); it++)
	{
		if ((*it).pobierz_cene() < cena)
		{
			lst.push_back(*it);
		}
	}

	return lst;
}

class Tanie
{
	int cena;
public:
	Tanie(int cena) : cena{ cena } {}
	bool operator()(Banknot k) const 
	{
		return k.pobierz_cene() < cena;
	}
};

void Kolekcja::usun_z_kolekcji(int cena)
{
	Tanie func(cena);

	banknoty.remove_if(func);
}

void Kolekcja::dodaj(std::list<Banknot>& lst)
{
	banknoty.splice(banknoty.end(), lst);
	lst.clear();
}

void Kolekcja::dodaj(Kolekcja& kol)
{
	banknoty.splice(banknoty.end(), kol.banknoty);
}

void Kolekcja::wczytaj(const char* path)
{
	std::ifstream file{ path };
	if (!file)
	{
		std::cerr << "Couldnt open a file\n";
	}

	for (std::string line; std::getline(file, line);)
	{
		std::istringstream str_stream{ line };
		Banknot k;
		str_stream >> k;
		banknoty.push_back(k);
	}

	file.close();
}

void Kolekcja::sortowanie()
{
	std::vector<Banknot> sL, sP;

	for (Banknot k : banknoty)
	{
		while (!sL.empty() && sL.back().pobierz_cene() <= k.pobierz_cene())
		{
			sP.push_back(sL.back());
			sL.pop_back();
		}

		while (!sP.empty() && sP.back().pobierz_cene() >= k.pobierz_cene())
		{
			sL.push_back(sP.back());
			sP.pop_back();
		}

		sL.push_back(k);
	}

	while (!sL.empty())
	{
		sP.push_back(sL.back());
		sL.pop_back();
	}

	banknoty.clear();
	while (!sP.empty())
	{
		banknoty.push_back(sP.back());
		sP.pop_back();
	}

	banknoty.reverse();
}