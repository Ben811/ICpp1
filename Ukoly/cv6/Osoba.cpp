#include "Osoba.h"

Osoba::Osoba(std::string jmeno, std::string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni)
{
	this->_jmeno = jmeno;
	this->_prijmeni = prijmeni;
	this->_trvaleBydliste = trvaleBydliste;
	this->_datumNarozeni = datumNarozeni;
}

Osoba::Osoba()
{
	this->_jmeno = "";
	this->_prijmeni = "";
	this->_trvaleBydliste = Adresa{};
	this->_datumNarozeni = Datum{};
}

std::string Osoba::getJmeno()
{
	return this->_jmeno;
}

std::string Osoba::getPrijmeni() const
{
	return this->_prijmeni;
}

Adresa Osoba::getTrvaleBydliste() const
{
	return this->_trvaleBydliste;
}

Datum Osoba::getDatumNarozeni() const
{
	return this->_datumNarozeni;
}

void Osoba::setJmeno(std::string jmeno)
{
	this->_jmeno = jmeno;
}

void Osoba::setPrijmeni(std::string prijmeni)
{
	this->_prijmeni = prijmeni;
}

void Osoba::setTrvaleBydliste(Adresa trvaleBydliste)
{
	this->_trvaleBydliste = trvaleBydliste;
}

void Osoba::setDatumNarozeni(Datum datumNarozeni)
{
	this->_datumNarozeni = datumNarozeni;
}

std::ostream& operator<<(std::ostream& os, const Osoba& obj)
{
	os << obj._jmeno << " " << obj._prijmeni << " " << obj._trvaleBydliste << " " << obj._datumNarozeni << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Osoba& obj)
{
	is >> obj._jmeno >> obj._prijmeni >> obj._trvaleBydliste >> obj._datumNarozeni;
	return is;
}