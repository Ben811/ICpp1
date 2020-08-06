#ifndef _ZPRAVAPORT_H
#define _ZPRAVAPORT_H
#include "Zprava.h"

struct ASitovyPrvek;
struct ZpravaPort
{
	ZpravaPort() { }
	ZpravaPort(Zprava* zprava, ASitovyPrvek* port) : zprava(zprava), port(port) {}
	Zprava* zprava;
	ASitovyPrvek* port;
};


#endif
