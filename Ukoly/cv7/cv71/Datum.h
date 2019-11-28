#ifndef _DATUM_H
#define _DATUM_H

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
	
	void writeToBinFile(std::ofstream& outfile,const std::string& file_name);
	int readFromBinFile(std::ifstream& infile,const std::string& file_name, Datum* buffer, int size_buffer);
private:
	int _den;
	int _mesic;
	int _rok;
};

#endif // !_DATUM_H
