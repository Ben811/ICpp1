#include "Cas.h"
#include <string>
using  namespace std;

Cas::Cas(int phodiny, int pMinuty, int pSekundy)
{
	_hodiny = phodiny;
	_minuty = pMinuty;
	_sekundy = pSekundy;
}

Cas::~Cas()
{
}

int Cas::compareTo(IComparable* obj) const
{
	Cas* cas = static_cast<Cas*>(obj);
	if (_hodiny == cas->_hodiny)
	{
		if (_minuty == cas->_minuty)
		{
			if (_sekundy == cas->_sekundy)
				return 0;
			else if (_sekundy > cas->_sekundy)
				return 1;
			else
				return -1;

		}
		else if (_minuty > cas->_minuty)
			return 1;
		else
			return -1;
	}
	else if (_hodiny > cas->_hodiny)
		return 1;
	else
		return -1;	
}

std::string Cas::toString() const
{
	return to_string(_hodiny) + ":" + to_string(_minuty) + ":" + to_string(_sekundy);
}
