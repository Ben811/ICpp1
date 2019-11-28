#ifndef _ADRESA_H
#define _ADRESA_H

#include <string>
#include <iostream>

struct Adresa
{
public:
	Adresa(std::string ulice, std::string mesto, int psc);
	Adresa();
	~Adresa() {};

	std::string getUlice() const;
	std::string getMesto() const;
	int getPSC() const;

	void setUlice(std::string ulice);
	void setMesto(std::string mesto);
	void setPSC(int psc);

	friend std::ostream& operator<<(std::ostream& os,const Adresa& obj);
	friend std::istream& operator>>(std::istream& is, Adresa& obj);
	
	void writeToBinFile(std::ofstream& outfile, const std::string& file_name);
	int readFromBinFile(std::ifstream& infile, std::string file_name, Adresa* buffer, int size_buffer);
private:
	std::string _ulice;
	std::string _mesto;
	int psc;
};

#endif 