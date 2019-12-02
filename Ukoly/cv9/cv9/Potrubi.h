#ifndef _POTRUBI_H
#define _POTRUBI_H
#include "IPotrubi.h"
#include <sstream>

struct Potrubi : IPotrubi
{
	Potrubi(std::istringstream* ss);
	~Potrubi() {}
	virtual const APotrubniPrvek* DejPrvek(int x, int y) const override;	
	virtual bool JePotrubiOk() const override;
private:
	APotrubniPrvek** prvky;
	int rozmer;
};

#endif