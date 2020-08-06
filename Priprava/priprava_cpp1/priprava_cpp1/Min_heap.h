#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H
#include "Data_structure_exception.h"

//in order to use this, the coparason operator < or > must be overloaded

template<typename Value>
class Min_heap
{
public:
	Min_heap();
	~Min_heap();
	void insert(Value* data);
	Value* remove_min();
	bool empty();
	int get_size() { return _curr_size; }
	int get_capacity() { return _capacity; }

private:
	void resize_heap();
	int get_index_parent(int index_child) { return (index_child - 1) / 2; }
	int get_index_left(int index_parent) { return 2 * index_parent + 1; }
	int get_index_right(int index_parent) { return 2 * index_parent + 2; }
	void switch_data(int index1, int index2);
	void heapify();
	void heapify_from_index(int index);
	
	Value** _heap_array;
	int _curr_size;
	int _capacity;

};

#endif

template<typename Value>
inline Min_heap<Value>::Min_heap()
{
	_capacity = 5;
	_heap_array = new Value * [_capacity];	
	_curr_size = 0;
}

template<typename Value>
inline Min_heap<Value>::~Min_heap()
{
	delete[] _heap_array;
}

template<typename Value>
inline void Min_heap<Value>::heapify()
{
		for (int i = 0; i < _curr_size; i++)
		{
			int index_parent = get_index_parent(i);
			if (*_heap_array[i] < *_heap_array[index_parent])
				switch_data(i, index_parent);
		}
}

template<typename Value>
inline void Min_heap<Value>::heapify_from_index(int index)
{
	while(true)
	{
		int parent = get_index_parent(index);
		if (parent == index ||*_heap_array[index] > *_heap_array[parent])
			return;
		switch_data(index, parent);
		index = parent;
	}
}

template<typename Value>
inline void Min_heap<Value>::insert(Value* data)
{
	if (data != nullptr)
	{
		if (_curr_size >= _capacity)
		{
			resize_heap();
		}
		_heap_array[_curr_size] = data;
		heapify_from_index(_curr_size++);
	}
	else
	{
		throw Data_structure_exception("Insert: data are nullptr");
	}
}

template<typename Value>
inline Value* Min_heap<Value>::remove_min()
{
	if (_curr_size > 0)
	{
		Value* retVal = _heap_array[0];
		_heap_array[0] = _heap_array[--_curr_size];
		heapify();
		return retVal;
	}
	else
	{
		throw Data_structure_exception("remove_min: heap is empty");
	}
}

template<typename Value>
inline bool Min_heap<Value>::empty()
{
	return _curr_size <= 0;
}

template<typename Value>
inline void Min_heap<Value>::resize_heap()
{
	_capacity = 2 * _capacity;
	Value** temp_arr = new Value * [_capacity];
	for (int i = 0; i < _curr_size; i++)
	{
		temp_arr[i] = _heap_array[i];
	}
	delete[] _heap_array;
	_heap_array = temp_arr;
}

template<typename Value>
inline void Min_heap<Value>::switch_data(int index1, int index2)
{
	if (index1 >= 0 && index2 >= 0 && index1 < _curr_size && index2 < _curr_size)
	{
		Value* data_index1 = _heap_array[index1];
		_heap_array[index1] = _heap_array[index2];
		_heap_array[index2] = data_index1;		
	}	
}
