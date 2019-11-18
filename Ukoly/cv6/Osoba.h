#ifndef __OSOBA
#define __OSOBA

#include <string>
#include <iostream>
#include "Adresa.h"
#include "Datum.h"

struct Osoba
{
public:
	Osoba(std::string jmeno, std::string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni);
	Osoba();

	std::string getJmeno();
	std::string getPrijmeni() const;
	Adresa getTrvaleBydliste() const;
	Datum getDatumNarozeni() const;

	void setJmeno(std::string jmeno);
	void setPrijmeni(std::string prijmeni);
	void setTrvaleBydliste(Adresa trvaleBydliste);
	void setDatumNarozeni(Datum datumNarozeni);

	friend std::ostream& operator<<(std::ostream& os, const Osoba& obj);
	friend std::istream& operator>>(std::istream& is, Osoba& obj);
private:
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;
};

#endif // !__OSOBA

