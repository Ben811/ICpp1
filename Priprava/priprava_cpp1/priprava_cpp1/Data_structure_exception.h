#ifndef _DATA_STRUCTURE_EXCEPTION_H
#define _DATA_STRUCTURE_EXCEPTION_H

#include <exception>
#include <string>
//catching a reference to this exception 
class Data_structure_exception : public std::exception
{
	std::string m_error;
public:
	Data_structure_exception(std::string error)
		: m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); } // C++11 version
};

#endif
