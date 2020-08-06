#ifndef _ZPRAVA_H
#define _ZPRAVA_H
#include <string>

struct Zprava
{
	Zprava() { }
	Zprava(int id, std::string adrZdroj, std::string adrCil, std::string obsah) :
		id(id), adrZdroj(adrZdroj), adrCil(adrCil), obsah(obsah) {
	}
private:
	int id;
	std::string adrZdroj;
	std::string adrCil;
	std::string obsah;
};
#endif
