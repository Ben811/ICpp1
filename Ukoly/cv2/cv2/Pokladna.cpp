#include <iostream>
#include <exception>
#include "Pokladna.h"

Pokladna::Pokladna()
{
	citacID = 1000;
	pocetVydanychUctenek = 0;
	poleUctenek = new Uctenka*[10];
}

Pokladna::~Pokladna()
{
	delete[] poleUctenek;
}

Uctenka& Pokladna::vystavUctenku(double castka, double dph)
{
	if (pocetVydanychUctenek >= 10)
	{
		throw std::overflow_error("Pokladna je plná");
	}
	poleUctenek[pocetVydanychUctenek] = new Uctenka(citacID, castka, dph);

	return *poleUctenek[pocetVydanychUctenek++];
}

Uctenka& Pokladna::dejUctenku(int x)
{
	if (pocetVydanychUctenek == 0)
	{
		throw std::overflow_error("zadna uctenka");
	}
	if (x > pocetVydanychUctenek-1)
	{
		return * poleUctenek[0];
	}
	return *poleUctenek[x];
}

int Pokladna::pocetVydanychUctenek = 0;

double Pokladna::dejCastku() const
{	
	double celkem = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		celkem += poleUctenek[pocetVydanychUctenek]->getCastka();
	}
	return celkem;
}

double Pokladna::dejCastkuVcDph() const
{
	double castkaVcDPH = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		castkaVcDPH = castkaVcDPH + poleUctenek[i]->getCastka() + (1 - poleUctenek[i]->getDPH());
	}
	return castkaVcDPH;
}
