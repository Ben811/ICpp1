#ifndef _ASITOVYPRVEK_H
#define _ASITOVYPRVEK_H
#include "ZpravaPort.h"
#include "Fronta.h"

struct ASitovyPrvek
{
	virtual ~ASitovyPrvek() {}
	void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void Provadej() = 0;
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) = 0;
	
protected: 	
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) = 0;
	Fronta<ZpravaPort> PrichoziZpravy;
};
#endif
