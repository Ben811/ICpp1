#include "Datum.h"

Datum::Datum(int den, int mesic, int rok) : _den(den), _mesic(mesic), _rok(rok)
{
}

Datum::Datum()
{
	this->_den = 0;
	this->_mesic = 0;
	this->_rok = 0;
}

int Datum::getDen() const
{
	return this->_den;
}

int Datum::getMesic() const
{
	return this->_mesic;
}

int Datum::getRok() const
{
	return this->_rok;
}

void Datum::setDen(int den)
{
	this->_den = den;
}

void Datum::setMesic(int mesic)
{
	this->_mesic = mesic;
}

void Datum::setRok(int rok)
{
	this->_rok = rok;
}

std::ostream& operator<<(std::ostream& os, const Datum& obj) {
	os << obj._den << ";" << obj._mesic << ";" << obj._rok;
	return os;
}

std::istream& operator>>(std::istream& is, Datum& obj) {
	is >> obj._den >> obj._mesic >> obj._rok;
	return is;
}