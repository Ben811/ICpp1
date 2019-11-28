#ifndef _MATICE_H
#define _MATICE_H

template<typename T>
class Matice
{
public:
	Matice(int rows, int columns);
	Matice(const Matice<T>& m);
	~Matice();

	void nastav(int row, int column, T hodnota);
	void nastavZ(T* pole);
	int getRows();
	int getColumns();;

	T& dej(int row, int column);
	const T& dej(int row, int column) const;

	template<class R>
	Matice<R> Pretypuj() const;

	Matice<T> Transpozice() const;
	Matice<T> Soucin(const Matice& m) const;
	Matice<T> Soucin(T skalar) const;
	Matice<T> Soucet(const Matice& m) const;
	Matice<T> Soucet(T skalar) const;
	
	bool JeShodna(const Matice& m) const;

	void Vypis() const;
	
private:
	T** _matice;
	int _rows;
	int _columns;
};

#endif


