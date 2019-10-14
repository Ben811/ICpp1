#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct Trojuhelnik {

	Trojuhelnik(int x, int y, int z) : X(x), Y(y), Z(z) {}
	int X;
	int Y;
	int Z;

};

void sestroj_trojuhelnik_1(int a, int b, int c);
void sestroj_trojuhelnik_1(Trojuhelnik *t);




int main()
{
	cout << "kolik trojuhelniku? : ";
	int pocet;
	cin >> pocet;
	Trojuhelnik** troj = new Trojuhelnik*[pocet];
	for (size_t i = 0;  i < pocet; i++)
	{
		int a, b, c;
		cout << "Zadej délku strany A" << endl;
		cin >> a;
		cout << "Zadej délku strany A" << endl;
		cin >> b;
		cout << "Zadej délku strany A" << endl;
		cin >> c;
		
		troj[i] = new Trojuhelnik(a, b, c);


		sestroj_trojuhelnik_1(troj[i]);

	}

	delete[] troj;

	
	
	
    return 0;
}

void sestroj_trojuhelnik_1(int a, int b, int c) {
	if (a + b > c || a + c > b || b + c > a)
	{
		cout << a + b + c << endl;
	}
	else
	{
		cout << "nelze sestrojit" << endl;
	}
}

void sestroj_trojuhelnik_1(Trojuhelnik* t) {
	int a = t->X;
	int b = t->Y;
	int c = t->Z;

	if (a + b > c || a + c > b || b + c > a)
	{
		cout << a + b + c << endl;
	}
	else
	{
		cout << "nelze sestrojit" << endl;
	}
}