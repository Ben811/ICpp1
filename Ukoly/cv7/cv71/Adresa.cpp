#include "Adresa.h"
#include <fstream>

Adresa::Adresa(std::string ulice, std::string mesto, int psc)
{
	_ulice = ulice;
	_mesto = mesto;
	this->psc = psc;
}

Adresa::Adresa()
{
	_ulice = "";
	_mesto = "";
	psc = 0;
}

std::string Adresa::getUlice() const
{
	return _ulice;
}

std::string Adresa::getMesto() const
{
	return _mesto;
}

int Adresa::getPSC() const
{
	return this->psc;
}

void Adresa::setUlice(std::string ulice)
{
	_ulice = ulice;
}

void Adresa::setMesto(std::string mesto)
{
	_mesto = mesto;
}

void Adresa::setPSC(int psc)
{
	this->psc = psc;
}

void Adresa::writeToBinFile(std::ofstream& outfile, const std::string& file_name)
{
	if (outfile.is_open())
		outfile.close();

	outfile.open(file_name, std::ios::binary | std::ios::out| std::ios::app);
	if (!outfile.is_open())
	{
		std::cerr << "Nastala chyba pri otevirani souboru: " << file_name << std::endl;
		return;
	}
	outfile.write((char*)this, sizeof(Adresa));
	outfile.close();
}

int Adresa::readFromBinFile(std::ifstream& infile, std::string file_name, Adresa* buffer, int size_buffer)
{
	if (infile.is_open())
		infile.close();

	infile.open(file_name, std::ios::binary | std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "nastala chyba pri otevirani souboru: " << file_name << std::endl;
		return -1;
	}
	
	int i;
	infile.seekg(0);
	for(i = 0; i <size_buffer; i++)
	{
		if (infile.eof())
			return i;
		infile.read((char*)&buffer[i], sizeof(Adresa));
	}
	infile.close();
	return 0;
}

std::ostream& operator<<(std::ostream& os,const Adresa& obj)
{
	os << obj.getUlice() << " "<< obj.getMesto() << " "<< std::to_string(obj.getPSC()) << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Adresa& obj)
{
	std::string pomocna{};
	int pom;

	is >> pomocna;
	obj.setUlice(pomocna);

	is >> pomocna;
	obj.setMesto(pomocna);

	is >> pom;
	obj.setPSC(pom);
	return is;
}
