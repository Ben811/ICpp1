#include "Adresa.h"

Adresa::Adresa(std::string ulice, std::string mesto, int psc)
{
	this->_ulice = ulice;
	this->_mesto = mesto;
	this->psc = psc;
}

Adresa::Adresa()
{
	this->_ulice = "";
	this->_mesto = "";
	this->psc = 0;
}

std::string Adresa::getUlice() const
{
	return this->_ulice;
}

std::string Adresa::getMesto() const
{
	return this->_mesto;
}

int Adresa::getPSC() const
{
	return this->psc;
}

void Adresa::setUlice(std::string ulice)
{
	this->_ulice = ulice;
}

void Adresa::setMesto(std::string mesto)
{
	this->_mesto = mesto;
}

void Adresa::setPSC(int psc)
{
	this->psc = psc;
}

std::ostream& operator<<(std::ostream& os, const Adresa& obj) {
	os << obj._ulice << ";" << obj._mesto << ";" << obj.psc;
	return os;
}

std::istream& operator>>(std::istream& is, Adresa& obj) {
	is >> obj._ulice >> obj._mesto >> obj.psc;
	return is;
}
