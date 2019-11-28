#include "Object.h"

void Seznam::pridejObject(Object& object)
{
	if (aktualni > velikost)
	{
		Object** temppole = new Object * [velikost * 2];
		for (int i = 0; i < velikost * 2; i++)
			temppole[i] = seznam[i];
		this->pridejObject(object);
		seznam = temppole;
		velikost++;
		delete[] temppole;
	}
	seznam[aktualni++];
}

Object** Seznam::getSeznam()
{
	return seznam;
}

int Seznam::getVelikost()
{
	return velikost;
}
