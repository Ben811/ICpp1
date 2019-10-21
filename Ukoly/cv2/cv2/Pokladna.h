
#ifndef POKLADNA_H
#define POKLADNA_H
#include "Uctenka.h"


class Pokladna {
public:
	Pokladna();
	~Pokladna();

	Uctenka& vystavUctenku(double castka, double dph);	
	Uctenka& dejUctenku(int x);	
	double dejCastku() const;
	double  dejCastkuVcDph() const;	
private:
	int  citacID;
	static int pocetVydanychUctenek;
	Uctenka** poleUctenek;

};


#endif // !POKLADNA_H
