#include "matice.h"
#include <iostream>

int main()
{
	Matice<int> m{ 3,3 };
	m.Vypis();
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.nastavZ(jednodpole);
	
	Matice<int> mt = m.Transpozice();
	Matice<int> mmt = m.Soucin(mt);
	Matice<double> mmt_d = mmt.Pretypuj<double>();
	Matice<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.nastavZ(jednodpole_d);
	Matice<double> mmtn_d = mmt_d.Soucin(n_d);
	Matice<int> r = mmtn_d.Pretypuj<int>();
	Matice<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.nastavZ(tpole);
	std::cout << "r==t ? " << (r.JeShodna(t) ? "true" : "false") << std::endl;
	
	return 0;
}