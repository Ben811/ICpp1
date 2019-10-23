#ifndef STATICKY_OBJEKT_H
#define STATICKY_OBJEKT_H
#include "Objekt.h"
#include "TypPrekazky.h"

class StatickyObjekt : public Objekt{
public:
	StatickyObjekt(int id, TypPrekazky typ);
	TypPrekazky getTypPrekazky();
private:
	TypPrekazky typPrekazky;
};



#endif // !STATICKY_OBJEKT_H
