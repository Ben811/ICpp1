
#include "Cas.h"
#include <iostream>

int main()
{
	Cas** s = new Cas*[10];
	s[0] = new Cas(10, 19, 17);
	s[1] = new Cas(19, 17, 15);
	s[2] = new Cas(17, 15, 13);
	s[3] = new Cas(15, 13, 12);
	s[4] = new Cas(13, 12, 11);
	s[5] = new Cas(12, 11, 18);
	s[6] = new Cas(11, 18, 16);
	s[7] = new Cas(18, 16, 13);
	s[8] = new Cas(16, 13, 10);
	s[9] = new Cas(13, 10, 19);
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++)
		{
			if (s[j]->compareTo(s[i]) == -1) {
				Cas* temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}		
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << s[i]->toString() << std::endl;
	}
	return 0;
}
