#ifndef __ADRESA
#define __ADRESA

#include <string>
#include <iostream>

struct Adresa
{
public:
	Adresa(std::string ulice, std::string mesto, int psc);
	Adresa();

	std::string getUlice() const;
	std::string getMesto() const;
	int getPSC() const;

	void setUlice(std::string ulice);
	void setMesto(std::string mesto);
	void setPSC(int psc);

	friend std::ostream& operator<<(std::ostream& os, const Adresa& obj);
	friend std::istream& operator>>(std::istream& is, Adresa& obj);
private:
	std::string _ulice;
	std::string _mesto;
	int psc;
};

#endif // !__ADRESA

