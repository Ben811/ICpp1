#include <fstream>
#include "Adresa.h"
#include "Datum.h"
#include "Osoba.h"

#include <fstream>
using namespace std;



int main()
{
	ifstream in{};
	ofstream out{};
	Datum datum1{ 7, 8, 1985 };
	Datum datum2{ 6, 7, 1976 };
	Datum datum3{ 9, 10, 1990 };

	Adresa adr1{ "Palackeho", "Praha", 10000 };
	Adresa adr2{ "Borovskeho", "Brno", 12600 };
	Adresa adr3{ "Nadrazni", "Zlin", 12003 };

	Osoba o1{ "Jan", "Novak", adr1, datum1 };
	Osoba o2{ "Petr", "Novotny", adr2, datum2 };
	Osoba o3{ "Frantisek", "Kratochvil", adr3, datum3 };
	
	std::string data = "file_osoby.dat";
	out.open(data, std::ios::out);
	out << o1 << o2 << o3;
	out.close();
	Osoba osoby[3];
	in.open(data, std::ios::in);
	in >> osoby[0] >> osoby[1] >> osoby[2];
	for (int i = 0; i < 3; i++)
		cout << osoby[i];
	return 0;
}
