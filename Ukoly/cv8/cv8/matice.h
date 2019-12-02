#ifndef _MATICE_H
#define _MATICE_H

#include <string>
#include <iostream>
#include <stdexcept>

class MaticeError : public std::runtime_error
{
public:
	MaticeError(const char* what) : runtime_error(what) {}
};

template<typename T>
class Matice
{
public:
	Matice(int rows, int columns);
	Matice(const Matice<T>& m);
	Matice();
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



template<typename T>
Matice<T>::Matice(int rows, int columns)
{
	_matice = new T * [rows];
	for (int i = 0; i < rows; i++) {
		_matice[i] = new T[columns];
	}

	_rows = rows;
	_columns = columns;
}

template<typename T>
Matice<T>::Matice(const Matice<T>& m)
{
	_rows = m._rows;
	_columns = m._columns;

	_matice = new T * [_rows];
	for (int i = 0; i < _rows; i++) {
		_matice[i] = new T[_columns];
	}

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _columns; j++)
		{
			nastav(i, j, m.dej(i, j));
		}

}

template<typename T>
Matice<T>::~Matice()
{
	for (int i = 0; i < _rows; i++)
		delete[] _matice[i];
	delete[] _matice;
}

template<typename T>
Matice<T>::Matice()
{
	_rows = 0;
	_columns = 0;
}

template<typename T>
void Matice<T>::nastav(int row, int column, T hodnota)
{
	if (row < 0 && column < 0 || row > _rows&& column < _columns)
		throw MaticeError("Out of bounds");

	_matice[row * _rows + column] = &hodnota;
}

template<typename T>
void Matice<T>::nastavZ(T* pole)
{
	int index = 0;
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			nastav(i, j, pole[index++]);
		}
	}

}

template<typename T>
int Matice<T>::getRows()
{
	return _rows;
}

template<typename T>
int Matice<T>::getColumns()
{
	return _columns;
}

template<typename T>
T& Matice<T>::dej(int row, int column)
{
	if (row < 0 && column < 0 || row > _rows&& column < _columns)
		throw MaticeError("Out of bounds");

	return _matice[row][column];
}

template<typename T>
const T& Matice<T>::dej(int row, int column) const
{
	if (row < 0 && column < 0 || row > _rows&& column < _columns)
		throw MaticeError("Out of bounds");

	return _matice[row][column];
}

template<typename T>
Matice<T> Matice<T>::Transpozice() const
{
	if (_rows != _columns)
		throw MaticeError("Matici nelze transponovat");

	Matice<T>* retMat = new Matice<T>(_rows, _columns);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			retMat->nastav(j, i, _matice[i][j]);

		}
	}
	return *retMat;
}

template<typename T>
Matice<T> Matice<T>::Soucin(const Matice& m) const
{

	if (_columns != m._rows)
		throw MaticeError("Matice nelze násobit");;

	Matice<T>* retMat = new Matice<T>(_rows, m._columns);
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < m._columns; j++)
		{
			{
				for (int k = 0; k <= m._columns; k++)
					retMat->nastav(i, j, _matice[i][k] + m.dej(k, j));
			}
		}
	return *retMat;
}

template<typename T>
Matice<T> Matice<T>::Soucin(T skalar) const
{
	Matice temp(_rows, _columns);
	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			temp[i][j] = _matice[i][j] * skalar;
	return temp;
}

template<typename T>
Matice<T> Matice<T>::Soucet(const Matice& m) const
{
	if (m._columns != _columns && m._rows != _rows)
		throw MaticeError("Matice nelze secist");

	Matice temp(_rows, _columns);
	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			temp[i][j] = _matice[i][j] + m[i][j];
	return temp;
}

template<typename T>
Matice<T> Matice<T>::Soucet(T skalar) const
{
	Matice temp(_rows, _columns);
	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			temp[i][j] = _matice[i][j] + skalar;
	return temp;
}

template<typename T>
bool Matice<T>::JeShodna(const Matice& m) const
{
	if (m._columns != _columns && m._rows != _rows)
		return false;

	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			if (_matice[i][j] != m.dej(i, j))
				return false;

	return true;
}

template<typename T>
void Matice<T>::Vypis() const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; i < _columns; i++)
			std::cout <<_matice[i][j] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
template<typename R>
Matice<R> Matice<T>::Pretypuj() const
{
	Matice<R>* temp = new Matice<R>(_rows, _columns);
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			temp->nastav(i, j, static_cast<R>(_matice[i][j]));
		}
	}
	return *temp;
}



#endif


