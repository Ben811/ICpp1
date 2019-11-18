#include <fstream>
#include "Adresa.h"
#include "Datum.h"
#include "Osoba.h"

using namespace std;

void uloz() {
	Datum datum1{ 7, 8, 1985 };
	Datum datum2{ 6, 7, 1976 };
	Datum datum3{ 9, 10, 1990 };

	Adresa adr1{ "Palackeho 264", "Praha", 10000 };
	Adresa adr2{ "Borovskeho 357", "Brno", 12600 };
	Adresa adr3{ "Nadrazni 120", "Zlin", 12003 };

	Osoba o1{ "Jan", "Novak", adr1, datum1 };
	Osoba o2{ "Petr", "Novotny", adr2, datum2 };
	Osoba o3{ "Frantisek", "Kratochvil", adr3, datum3 };

	Osoba osoby[3] = { o1, o2, o3 };

	ofstream out{};
	out.open("pokus.txt");

	if (out.is_open()) {
		for (int i = 0; i < 3; i++) {
			out << osoby[i] << endl;
		}
		out.close();
	}
	else {
		cerr << "Soubor se nepodarilo otevrit...";
	}
}

void nacti() {
	string line;
	ifstream in{};
	std::string delimiter = ";";

	in.open("pokus.txt");

	int amount = 0;

	if (in.is_open()) {
		while (getline(in, line)) {
			amount++;
		}

		in.close();
	}

	Osoba* osoby = new Osoba[amount + 1];

	in.open("pokus.txt");

	if (in.is_open()) {
		while (getline(in, line)) {
			cout << text << endl;
		}

		in.close();
	}

	
}

int main()
{
	Datum dat{ 30, 10, 2019 };
	std::cout << "Test:\t" << dat << std::endl;

	Adresa adr{ "Nr", "Pardubice", 1234 };
	std::cout << "Test2:\t" << adr << std::endl;

	Osoba o{ "Jan", "Novak", adr, dat };

	std::cout << "Test3\t" << o << endl;

	uloz();
	nacti();
}
