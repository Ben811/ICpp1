#ifndef POHYBLIVY_OBJEKT_H
#define POHYBLIVY_OBJEKT_H

#include "Objekt.h"

class PohyblivyObjekt : public Objekt {
public:
	PohyblivyObjekt(int id);
	virtual ~PohyblivyObjekt();

	void setUhel(double value);
	double getUhel();
private:
	double uhel;	
};

#endif // !POHYBLIVY_OBJEKT_H
