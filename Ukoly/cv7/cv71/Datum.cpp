#include "Datum.h"
#include <fstream>

Datum::Datum(int den, int mesic, int rok)
{
	_den = den;
	_mesic = mesic;
	_rok = rok;
}

Datum::Datum()
{
	this->_den = 0;
	this->_mesic = 0;
	this->_rok = 0;
}

int Datum::getDen() const
{
	return _den;
}

int Datum::getMesic() const
{
	return _mesic;
}

int Datum::getRok() const
{
	return _rok;
}

void Datum::setDen(int den)
{
	_den = den;
}

void Datum::setMesic(int mesic)
{
	_mesic = mesic;	
}

void Datum::setRok(int rok)
{
	_rok = rok;
}

void Datum::writeToBinFile(std::ofstream& outfile, const std::string& file_name)
{
	if (!outfile.is_open())
		outfile.close();

	outfile.open(file_name, std::ios::binary | std::ios::out | std::ios::app);
	if (!outfile.is_open())
	{
		std::cerr << "Nastala chyba pri otevirani souboru: " << file_name;
		return;
	}

	outfile.write((char*)this, sizeof(Datum));
	outfile.close();
}

int Datum::readFromBinFile(std::ifstream& infile, const std::string& file_name, Datum* buffer, int size_buffer)
{
	if (infile.is_open())
		infile.close();

	infile.open(file_name, std::ios::binary | std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "Chyba pri otevirani souboru: " << file_name << std::endl;
		return 0;
	}
	int i;
	for (i = 0; i < size_buffer; i++) {
		if (infile.eof())
			return i;
		infile.read((char*)&buffer[i], sizeof(Datum));
	}
	infile.close();
	return i;
}

std::ostream& operator<<(std::ostream& os, const Datum& obj) {
	os << obj._den << " " << obj._mesic << " " << obj._rok << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Datum& obj) {
	is >> obj._den >> obj._mesic >> obj._rok;
	return is;
}