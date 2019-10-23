#include "StatickyObjekt.h"

StatickyObjekt::StatickyObjekt(int id, TypPrekazky typ) : Objekt(id), typPrekazky(typ) {}

TypPrekazky StatickyObjekt::getTypPrekazky()
{
	return typPrekazky;
}
