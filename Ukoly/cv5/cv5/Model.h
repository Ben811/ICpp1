#ifndef _MODEL_H
#define  _MODEL_H
#include <stdexcept>
#include "Entity.h"


namespace Model
{
	struct person_not_found : public std::exception
	{
		const char* what() throw ()
		{
			return "Person not found";
		}
	};

	struct PrvekSeznam
	{
	public:
		explicit PrvekSeznam(const Entiti::Osoba& pOsoba) : osoba(pOsoba), dalsi(nullptr) {}
		~PrvekSeznam() {}
		Entiti::Osoba* getOsoba()
		{
			return &osoba;
		}
		PrvekSeznam* getDalsi()
		{
			return dalsi;
		}
		void setDalsi(PrvekSeznam* next)
		{
			dalsi = next;
		}
	private:
		Entiti::Osoba osoba;
		PrvekSeznam* dalsi;
	};

	class TelefonniSeznam
	{
	public:
		void pridejOsobu(Entiti::Osoba* o)
		{
			if (prvni == nullptr)
			{
				prvni = new PrvekSeznam(*o);
			}
			else {
				PrvekSeznam* traverse_prvek = prvni;
				while (traverse_prvek->getDalsi() != nullptr)
				{
					traverse_prvek = traverse_prvek->getDalsi();
				}
				traverse_prvek->setDalsi(new PrvekSeznam(*o));
			}
		}

		std::string najdiTelefon(std::string jmeno) const
		{
			if (jmeno == "")
			{
				throw std::invalid_argument("Invalid argument");
			}
			PrvekSeznam* traverse_prvek = prvni;
			while (traverse_prvek->getDalsi() != nullptr)
			{
				if (traverse_prvek->getOsoba()->getJmeno() == jmeno)
				{
					return traverse_prvek->getOsoba()->getTelefon();
				}
				traverse_prvek = traverse_prvek->getDalsi();
			}
			throw person_not_found();

		}
		std::string najdiTelefon(int id) const
		{
			if (id < 0)
			{
				throw std::invalid_argument("Invalid argument");
			}
			PrvekSeznam* traverse_prvek = prvni;
			while (traverse_prvek->getDalsi() != nullptr)
			{
				if (traverse_prvek->getOsoba()->getId() == id)
				{
					return traverse_prvek->getOsoba()->getTelefon();
				}
				traverse_prvek = traverse_prvek->getDalsi();
			}
			throw person_not_found();
		}
	private:
		PrvekSeznam* prvni;
	};


}

#endif
