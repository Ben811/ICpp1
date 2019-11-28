#include "Adresa.h"
#include "Osoba.h"
#include "Datum.h"

#include <fstream>

int main()
{
	std::ifstream in{};
	std::ofstream out{};
	
	const std::string adresy = "adresy.dat";
	const int velikostPoleA = 3;
	Adresa poleA[velikostPoleA];
	Adresa adresa1{ "ulice1", "mesto1", 1 };
	Adresa adresa2{ "ulice2", "mesto2", 2 };
	Adresa adresa3{ "ulice3", "mesto3", 3 };
	adresa1.writeToBinFile(out,adresy);
	adresa2.writeToBinFile(out, adresy);
	adresa3.writeToBinFile(out, adresy);
	adresa1.readFromBinFile(in, adresy, poleA, velikostPoleA);
	for (int i = 0; i < velikostPoleA; i++)
		std::cout << poleA[i];

	const std::string datum_file = "datum.dat";
	const int velikostPoleB = 3;
	Datum poleB[velikostPoleB];
	Datum datum1{ 10,10,1111 };
	Datum datum2{ 11,11,1112 };
	Datum datum3{ 12,12,1113 };
	datum1.writeToBinFile(out, datum_file);
	datum2.writeToBinFile(out, datum_file);
	datum3.writeToBinFile(out, datum_file);
	datum1.readFromBinFile(in, datum_file,poleB, velikostPoleB);
	for (int i = 0; i < velikostPoleB; i++)
		std::cout << poleB[i];
	
	const std::string osoby_file = "osoby.dat";
	const int velikostPoleC = 3;
	Osoba poleC[velikostPoleC];
	Osoba a{ "a","aa",adresa1, datum1 };
	Osoba b{ "b","bb",adresa2, datum2 };
	Osoba c{ "c","cc",adresa3, datum3 };
	a.writeToBinFile(out, osoby_file);
	b.writeToBinFile(out, osoby_file);
	c.writeToBinFile(out, osoby_file);
	a.readFromBinFile(in, osoby_file, poleC, velikostPoleC);
	for (int i = 0; i < velikostPoleC; i++)
		std::cout << poleC[i];
	
	
	return 0;
}
