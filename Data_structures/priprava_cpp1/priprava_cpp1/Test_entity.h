#ifndef _TEST_ENTITY_H
#define _TEST_ENTITY_H
#include <fstream>
#include <string>

class Test_entity
{
public:
	Test_entity(int value): _value(value){}
	int get_value() { return _value; }
	friend bool operator>(Test_entity& t1, Test_entity& t2);
	friend bool operator<(Test_entity& t1, Test_entity& t2);
	friend std::ostream& operator<<(std::ostream& os, Test_entity& t);	
private:
	int _value;
	
};

inline bool operator>(Test_entity& t1, Test_entity& t2)
{
	return t1._value>t2._value;
}

inline bool operator<(Test_entity& t1, Test_entity& t2)
{
	return t1._value<t2._value;
}

inline std::ostream& operator<<(std::ostream& os, Test_entity& t)
{
	os << std::to_string(t._value);
	return os;
}
#endif
