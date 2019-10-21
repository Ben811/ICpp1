// cv2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <iostream>

#include "Uctenka.h"
#include "Pokladna.h"

using namespace std;
int main()
{
	Pokladna* temp = new Pokladna();
	temp->vystavUctenku(100, 10);
	temp->vystavUctenku(101, 11);
	temp->vystavUctenku(102, 12);

	Uctenka* tUctenka = &temp->dejUctenku(0);

	tUctenka->tostring();

	return 0;
}

