#include "Hra.h"


Hra::Hra()
{
	velikostPole = 0;
	objekty = new Objekt * [0];
}

Hra::~Hra()
{
	for (int i = 0; i < velikostPole; i++)
	{
		delete objekty[i];
	}
}

void Hra::vlozObjekt(Objekt* o)
{
	Objekt** tempO = new Objekt * [velikostPole+1];
	for (int i = 0; i < velikostPole; i++)
	{
		tempO[i] = objekty[i];
	}
	tempO[velikostPole++] = o;
	delete[] objekty;
	objekty = tempO;
}

int* Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax)
{
	int* poleId = new int[10];
	int velikostTemp = 0;
	for (int i = 0; i < velikostPole; i++)
	{
		StatickyObjekt* so = dynamic_cast<StatickyObjekt*>(objekty[i]);
		if (so != nullptr)
		{
			if (so->getX() >= xmin && so->getX() <= xmax && so->getY() >= ymin && so->getY() <= xmax)
			{
				int* tempole = new int[velikostTemp *2];
				for (int i = 0; i < velikostTemp; i++)
				{
					tempole[i] = poleId[i];
				}
				tempole[velikostTemp++] = so->getID();
				delete[] poleId;
				poleId = tempole;
			}
		}
	}
	return poleId;//velmi pravdìpodobný memory leak
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{
	PohyblivyObjekt** polePObjektu = new PohyblivyObjekt * [10];
	int velikostTemp = 0;
	for (int i = 0; i < velikostTemp; i++)
	{
		PohyblivyObjekt* po = dynamic_cast<PohyblivyObjekt*>(objekty[i]);
		if (po != nullptr)
		{
			double vzdalenost = sqrt(pow(x - po->getX(), 2) + pow(y - po->getY(), 2));
			if (vzdalenost <= r)
			{
				PohyblivyObjekt** tempole = new PohyblivyObjekt * [velikostTemp*2];
				for (int i = 0; i < velikostTemp; i++)
				{
					tempole[i] = polePObjektu[i];
				}
				tempole[velikostTemp++] = po;
				delete[] polePObjektu;
				polePObjektu = tempole;
			}
			
		}
	}
	return polePObjektu;//velmi pravdìpodobný memory leak
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax)
{
	
	PohyblivyObjekt** poleToSort = najdiPohybliveObjektyVOblasti(x, y, r);	
	PohyblivyObjekt** polePObjektuUhel = new PohyblivyObjekt * [10];

	int velikostPPO = sizeof(poleToSort) / sizeof(*poleToSort);
	int velikostPPOUhel = 0;

	for (int i = 0; i < velikostPPO; i++)
	{
		if (poleToSort[i]->getUhel() >= umin && poleToSort[i]->getUhel() <= umax)
		{
			PohyblivyObjekt** tempole = new PohyblivyObjekt * [velikostPPOUhel*2];
			for (int j = 0; j < velikostPPOUhel; j++)
			{
				tempole[j] = polePObjektuUhel[j];
			}
			tempole[velikostPPOUhel++] = poleToSort[i];
			delete[] polePObjektuUhel;
			polePObjektuUhel = tempole;
		}

	}
	delete[] poleToSort;

	return polePObjektuUhel;
}
