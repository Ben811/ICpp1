#include "Uctenka.h"
#include <iostream>

Uctenka::Uctenka() : cisloUctenky(0), castka(0), dph(0) {}

Uctenka::Uctenka(int pCisloUcteny, double pCastka, double pDph): cisloUctenky(pCisloUcteny), castka(pCastka), dph(pDph){}

int Uctenka::getCisloUctenky()
{
	return cisloUctenky;
}

double Uctenka::getCastka()
{
	return castka;
}

double Uctenka::getDPH()
{
	return dph;
}

void Uctenka::setCisloUctenky(int cisloU)
{
	cisloUctenky = cisloU;
}

void Uctenka::setCastka(double pCastka)
{
	castka = pCastka;
}

void Uctenka::setDPH(double pDPH)
{
	dph = pDPH;
}

void Uctenka::tostring()
{
	std::cout << cisloUctenky << ", " << castka << ", " << dph << std::endl;
}
