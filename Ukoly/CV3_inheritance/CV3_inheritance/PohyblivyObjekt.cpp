#include "PohyblivyObjekt.h"

PohyblivyObjekt::PohyblivyObjekt(int pId) : Objekt(pId)
{
	uhel = 0;
}

PohyblivyObjekt::~PohyblivyObjekt()
{
}

void PohyblivyObjekt::setUhel(double value)
{
	uhel = value;
}

double PohyblivyObjekt::getUhel()
{
	return uhel;
}
