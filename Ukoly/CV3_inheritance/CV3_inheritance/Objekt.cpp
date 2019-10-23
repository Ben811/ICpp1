#include "Objekt.h"

Objekt::Objekt(int id) : id(id), x(0), y(0)
{
}

Objekt::~Objekt()
{
}

int Objekt::getID()
{
	return id;
}

double Objekt::getX()
{
	return x;
}

double Objekt::getY()
{
	return y;
}

void Objekt::setX(int value)
{
	x = value;
}

void Objekt::setY(int value)
{
	y = value;
}
