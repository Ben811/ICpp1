#include "matice.h"
#include <string>
#include <iostream>


template<typename T>
Matice<T>::Matice(int rows, int columns)
{
	_matice = new Matice<T>[rows][columns];
	for (int i = 0; i < rows * columns; i++)
		_matice[i] = nullptr;

	_rows = rows;
	_columns = columns;
}

template<typename T>
Matice<T>::Matice(const Matice<T>& m)
{
	nastavZ(m);
	_rows = m.getRows();
	_columns = m.getColumns();
}

template<typename T>
Matice<T>::~Matice()
{
}

template<typename T>
void Matice<T>::nastav(int row, int column, T hodnota)
{
	_matice[row][column] = hodnota;
}

template<typename T>
void Matice<T>::nastavZ(T* pole)
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matice[i][j] = pole[i * _rows + j];
			//nastav(i, j, pole[i * _rows + j]);
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
	return _matice[row][column];
}

template<typename T>
const T& Matice<T>::dej(int row, int column) const
{
	return _matice[row][column];
}

template<typename T>
Matice<T> Matice<T>::Transpozice() const
{
	if (_rows != _columns)
		return nullptr;
		
	Matice<T> retMat[_rows][_columns];
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			retMat[i][j] = _matice[j][i];
		}
	}
	return retMat;
}

template<typename T>
Matice<T> Matice<T>::Soucin(const Matice& m) const
{
	
	if (this->_columns != m.getRows())
		return nullptr;

	Matice temp(_rows, m.getColumns());
	for (int i = 0; i < temp.getRows(); i++)
		for (int j = 0; j < temp.getColumns(); j++)
		{
			temp[i][j] = 0;
			{
				for (int k = 0; k <= temp.col; k++)
					temp[i][j] += _matice[i][k] * m[k][j];
			}
		}
	return temp;
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
	if (m.getColumns() != _columns && m.getRows() != _rows)
		return nullptr;
	
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
	if (m.getColumns() != _columns && m.getRows() != _rows)
		return false;

	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			if (_matice[i][j] != m[i][j])
				return false;
	
	return true;
}

template<typename T>
void Matice<T>::Vypis() const
{
	for (int i = 0; i < _rows; i++)
		for (int j = 0; i < _columns; i++)
			std::cout << std::to_string(_matice[i][j]);
}

template<typename T>
template<typename R>
Matice<R> Matice<T>::Pretypuj() const
{
	Matice<R> retMat[_rows][_columns];
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			retMat[i][j] = _matice[i][j];
		}
	}
	return retMat;
}

