#ifndef _OSOBA_H
#define _OSOBA_H
#include <string>
#include "Adresa.h"
#include "Datum.h"

struct Osoba
{
public:
	Osoba(std::string jmeno, std::string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni);
	Osoba();

	std::string getJmeno() const;
	std::string getPrijmeni() const;
	Adresa getTrvaleBydliste() const;
	Datum getDatumNarozeni() const;

	friend std::ostream& operator<<(std::ostream& os, const Osoba& obj);
	friend std::istream& operator>>(std::istream& is, Osoba& obj);
	
	void writeToBinFile(std::ofstream& outfile, std::string file_name);
	int readFromBinFile(std::ifstream& infile, std::string file_name, Osoba* buffer, int size_buffer);
private:
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;
	
};
#endif
