#ifndef _FRONTA_H
#define _FRONTA_H
template<typename T>
struct Fronta
{
	Fronta();
	Fronta(const Fronta& f);
	~Fronta();

	void Vloz(T hodnota);
	T Odeber();
	bool Obsahuje(T hodnota) const;
	using ApplyFunkce = void(*) (T);
	void ZpracujPrvky(ApplyFunkce f);
	bool JePrazdna() const;
private:
	struct El {
		T hodnota;
		El* dalsi;
		El* predchozi;
	};
	El* prvni;
	El* posledni;

};
#endif

template<typename T>
inline Fronta<T>::Fronta()
{
	prvni = nullptr;
	posledni = nullptr;
}

template<typename T>
inline Fronta<T>::Fronta(const Fronta& f)
{
	El* it = f.prvni;
	while (it) {
		Vloz(it->hodnota);
		it = it->dalsi;
	}

}

	template<typename T>
	inline Fronta<T>::~Fronta()
	{
		while (prvni) {
			El* tmp = prvni;
			prvni = prvni->dalsi;
			delete tmp;
		}
	}



template<typename T>
inline void Fronta<T>::Vloz(T hodnota)
{
	posledni = new El{ hodnota, nullptr, posledni };
	if (!prvni)
		prvni = posledni;
	else
		posledni->predchozi->dalsi = posledni;
}

template<typename T>
inline T Fronta<T>::Odeber()
{
	T hodnota = posledni->hodnota;
	El* tmp = posledni;
	if (posledni->predchozi) {
		posledni = posledni->predchozi;
		posledni->dalsi = nullptr;
	}
	else {
		posledni = nullptr;
		prvni = nullptr;
	}
	delete tmp;
	return hodnota;
}

template<typename T>
inline bool Fronta<T>::Obsahuje(T hodnota) const
{
	El* el = prvni;
	while (el) {
		if (el->hodnota == hodnota)
			return true;
		el = el->dalsi;
	}
	return false;
}

template<typename T>
inline void Fronta<T>::ZpracujPrvky(ApplyFunkce f)
{
	El* el = prvni;
	while (el) {
		f(el->hodnota);
		el = el->dalsi;
	}

}

template<typename T>
inline bool Fronta<T>::JePrazdna() const
{
	return prvni == nullptr;

}
