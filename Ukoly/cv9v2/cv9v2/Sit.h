#ifndef  _SIT_H
#define _SIT_H
#include "ASitovyPrvek.h"

struct Sit
{
	int dejNoveid();
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void ProvadejVse();
private:
	int idZpravy;
	Fronta<ASitovyPrvek*> sitovePrvky;
};

#endif
