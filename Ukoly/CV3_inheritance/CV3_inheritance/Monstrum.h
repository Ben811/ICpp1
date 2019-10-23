#ifndef MONSTRUM_H
#define MONSTRUM_H

#include "PohyblivyObjekt.h"


class Monstrum : PohyblivyObjekt {
public:
	Monstrum(int id, int pHp, int pMaxhp);
	
	int getMaxHp();
	int getHp();

	void setMaxHp(int pMaxHP);
	void setHp(int pHp);
private:
	int hp;
	int maxhp;
};
#endif // !MONSTRUM_H
