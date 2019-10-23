#include "Monstrum.h"

Monstrum::Monstrum(int pId, int pHp, int pMaxhp) : PohyblivyObjekt(pId), hp(pHp), maxhp(pMaxhp)
{

}

int Monstrum::getMaxHp()
{
	return maxhp;
}

int Monstrum::getHp()
{
	return hp;
}

void Monstrum::setMaxHp(int pMaxHP)
{
	maxhp = pMaxHP;
}

void Monstrum::setHp(int pHp)
{
	hp = pHp;
}
