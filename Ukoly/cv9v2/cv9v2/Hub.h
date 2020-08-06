#ifndef _HUB_H
#define _HUB_H
#include "ASitovyPrvek.h"
#include "Fronta.h"
struct Hub : ASitovyPrvek
{
	Hub(int maximumPripojenychPrvku);
	~Hub();
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void Provadej();

	private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*>* zpracovaneZpravy;

	void ZpracujPredchoziZpravu(ZpravaPort zp);
};
#endif
