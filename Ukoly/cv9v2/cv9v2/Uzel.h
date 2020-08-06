#ifndef _UZEL_H
#define _UZEL_H
#include <string>
#include "ASitovyPrvek.h"
#include "Fronta.h"

struct Uzel : ASitovyPrvek
{
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void Provadej();
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);
private:
	std::string adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;
	void ZpracujPredchoziZpravu(ZpravaPort zp);
	
};
#endif

