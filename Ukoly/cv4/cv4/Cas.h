#ifndef CAS_H
#define CAS_H
#include "IComparable.h"
struct Cas : IComparable
{
public:
	virtual int compareTo(IComparable* obj) const override;
	virtual std::string toString() const override;
private:
	int _hodiny;
	int _minuty;
	int _sekundy;
};
#endif // !CAS_H
