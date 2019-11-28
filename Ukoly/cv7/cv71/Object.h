#ifndef _OBJECT_H
#define _OBJECT_H

class Object
{
public:
	Object() {}
	~Object() {}
};

class Seznam
{
public:
	Seznam()
	{
		seznam = new Object * [100];
		velikost = 0;
		aktualni = 0;
	};
	~Seznam()
	{
		for (int i = 0; i < velikost; i++)
			delete seznam[i];
		delete[] seznam;
	};
	void pridejObject(Object& object);
	Object** getSeznam();
	int getVelikost();
private:
	Object** seznam;
	int velikost;
	int aktualni;
};
#endif
