#include "Osoba.h"
#include <fstream>

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

Osoba::Osoba(std::string jmeno, std::string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni)
{
	_jmeno = jmeno;
	_prijmeni = prijmeni;
	_trvaleBydliste = trvaleBydliste;
	_datumNarozeni = datumNarozeni;
}

Osoba::Osoba()
{
	this->_jmeno = "";
	this->_prijmeni = "";
	this->_trvaleBydliste = Adresa{};
	this->_datumNarozeni = Datum{};
}

std::string Osoba::getJmeno() const
{
	return _jmeno;
}

std::string Osoba::getPrijmeni() const
{
	return _prijmeni;
}

Adresa Osoba::getTrvaleBydliste() const
{
	return _trvaleBydliste;
}

Datum Osoba::getDatumNarozeni() const
{
	return _datumNarozeni;
}

void Osoba::writeToBinFile(std::ofstream& outfile, std::string file_name)
{
	if (outfile.is_open())
		outfile.close();
	
	outfile.open(file_name, std::ios::binary | std::ios::out | std::ios::app);

	if (!outfile.is_open()) {
		std::cerr << "Nastala chyba pøi otevírání souboru: " << file_name << std::endl;
		return;
	}

	outfile.write((char*)this, sizeof(Osoba));
	outfile.close();	
}

int Osoba::readFromBinFile(std::ifstream& infile, std::string file_name, Osoba* buffer, int size_buffer)
{
	if (infile.is_open())
		infile.close();

	infile.open(file_name, std::ios::binary | std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "Chyba pri otevírani souboru: " << file_name << std::endl;
		return -1;
	}
	int i;
	for ( i = 0; i < size_buffer; i++)
	{
		if (infile.eof())
		{
			return i;
		}
		infile.read((char*)&buffer[i], sizeof(Osoba));
	}
	infile.close();
	return i;
}

