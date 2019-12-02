#ifndef _PRVKY_POTRUBI_H
#define _PRVKY_POTRUBI_H

#include "IPotrubi.h"

struct PrvekMinus : APotrubniPrvek
{
	PrvekMinus(int x, int y) { _x = x; _y = y; }	
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};

struct PrvekI : APotrubniPrvek
{
	PrvekI(int x, int y) { _x = x; _y = y; }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};

struct PrvekPlus : APotrubniPrvek
{
	PrvekPlus(int x, int y) { _x = x; _y = y; }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};

struct PrvekO : APotrubniPrvek
{
	PrvekO(int x, int y) { _x = x; _y = y; }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};

struct PrvekT : APotrubniPrvek
{
	PrvekT(int x, int y) { _x = x; _y = y; }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};

struct PrvekNic : APotrubniPrvek
{
	PrvekNic(int x, int y) { _x = x; _y = y; }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const;
};
#endif
