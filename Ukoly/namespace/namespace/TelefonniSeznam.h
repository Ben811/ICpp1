#ifndef TELEFONNI_SEZNAM_H
#define TELEFONNI_SEZNAM_H
#include "Osoba.h"

namespace Model
{
	struct PrvekSeznam
	{
		Entity::Osoba data;
		PrvekSeznam* dalsi;		
	};

	struct list
	{
	private:
		PrvekSeznam* zacatek;
	public:
		void pridej(Entity::Osoba o);
		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const;
	};
	
	class TelefonniSeznam
	{
	public:
		TelefonniSeznam();
		~TelefonniSeznam();
	};
	
}

#endif



