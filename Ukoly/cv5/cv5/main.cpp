

#include <exception>
#include <string>
#include <stdexcept>

namespace Entiti
{
	class Osoba
	{
	public:
		Osoba(std::string pJmeno, std::string pTelefon, int pId) : jmeno(pJmeno), telefon(pTelefon), id(pId){}
		Osoba(std::string pJmeno, std::string pTelefon) : jmeno(pJmeno), telefon(pTelefon), id(0) {}
		Osoba(std::string pJmeno) : jmeno(pJmeno), telefon("123456789"), id(0) {}
		Osoba(const Osoba& posoba) : jmeno(posoba.jmeno), telefon(posoba.telefon), id(posoba.id){}
		~Osoba(){}

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
 namespace Model
{
	 struct person_not_found : public std::exception
	 {
		 const char* what() throw ()
		 {
			 return "Person not found";
		 }
	 };
	
	 class PrvekSeznam
	 {
	 public:
		 explicit PrvekSeznam(const Entiti::Osoba& pOsoba): osoba(pOsoba), dalsi(nullptr){}
		~PrvekSeznam(){}
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
			 PrvekSeznam* traverse_prvek = prvni;
			 while (traverse_prvek->getDalsi() != nullptr)
			 {
				 traverse_prvek = traverse_prvek->getDalsi();
			 }
			 traverse_prvek->setDalsi(new PrvekSeznam(*o));
				 
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
 int main()
{
	 return 0;
}