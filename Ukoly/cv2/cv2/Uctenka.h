#ifndef UCTENKA_H
#define UCTENKA_H

class Uctenka {
public:
	Uctenka();
	Uctenka(int pCisloUcteny, double pCastka, double pDph);
	int getCisloUctenky();
	double getCastka();
	double getDPH();
	void setCisloUctenky(int cisloU);
	void setCastka(double pCastka);
	void setDPH(double pDPH);
	void tostring();
private:
	int cisloUctenky;
	double castka;
	double dph;
};

#endif // !UCTENKA_H
