#ifndef _ENTITY_H
#define _ENTITY_H
#include <exception>
#include <string>
#include <stdexcept>

namespace Entiti
{
	class Osoba
	{
	public:
		Osoba(std::string pJmeno, std::string pTelefon, int pId) : jmeno(pJmeno), telefon(pTelefon), id(pId) {}
		Osoba(std::string pJmeno, std::string pTelefon) : jmeno(pJmeno), telefon(pTelefon), id(0) {}
		Osoba(const Osoba& posoba) : jmeno(posoba.jmeno), telefon(posoba.telefon), id(posoba.id) {}
		~Osoba() {}

		std::string getJmeno()
		{
			return jmeno;
		}
		std::string getTelefon()
		{
			return telefon;
		}
		int getId()
		{
			return id;
		}
		void setId(int pId)
		{
			id = pId;
		}
		void setJmeno(std::string pJmeno)
		{
			jmeno = pJmeno;
		}
		void setTelefon(std::string pTelefon)
		{
			telefon = pTelefon;
		}
	private:
		std::string jmeno;
		std::string telefon;
		int id;
	};
}
#endif
