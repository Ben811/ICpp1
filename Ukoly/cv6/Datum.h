#ifndef __DATUM
#define __DATUM

#include <iostream>

struct Datum
{
public:
	Datum(int den, int mesic, int rok);
	Datum();

	int getDen() const;
	int getMesic() const;
	int getRok() const;

	void setDen(int den);
	void setMesic(int mesic);
	void setRok(int rok);

	friend std::ostream& operator<<(std::ostream& os, const Datum& obj);
	friend std::istream& operator>>(std::istream& is, Datum& obj);
private:
	int _den;
	int _mesic;
	int _rok;
};

#endif // !__DATUM
