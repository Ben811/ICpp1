#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H
template<typename T>
class Max_heap {
public:
	Max_heap();
	~Max_heap();
	void insert(T* data);
	T* remove_max();
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

	T** _heap_array;
	int _curr_size;
	int _capacity;
};


#endif

template<typename T>
inline Max_heap<T>::Max_heap()
{
	_capacity = 5;
	_curr_size = 0;
	_heap_array = new T * [_capacity];
}

template<typename T>
inline Max_heap<T>::~Max_heap()
{
	delete[] _heap_array;
}

template<typename T>
inline void Max_heap<T>::insert(T* data)
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

template<typename T>
inline T* Max_heap<T>::remove_max()
{
	if (_curr_size > 0)
	{
		T* retVal = _heap_array[0];
		_heap_array[0] = _heap_array[--_curr_size];
		heapify();
		return retVal;
	}
	else
	{
		throw Data_structure_exception("remove_max: heap is empty");
	}
}

template<typename T>
inline bool Max_heap<T>::empty()
{
	return _curr_size <= 0;
}

template<typename T>
inline void Max_heap<T>::resize_heap()
{
	_capacity = 2 * _capacity;
	T** temp_arr = new T * [_capacity];
	for (int i = 0; i < _curr_size; i++)
	{
		temp_arr[i] = _heap_array[i];
	}
	delete[] _heap_array;
	_heap_array = temp_arr;
}

template<typename T>
inline void Max_heap<T>::switch_data(int index1, int index2)
{
	if (index1 >= 0 && index2 >= 0 && index1 < _curr_size && index2 < _curr_size)
	{
		T* data_index1 = _heap_array[index1];
		_heap_array[index1] = _heap_array[index2];
		_heap_array[index2] = data_index1;
	}
}

template<typename T>
inline void Max_heap<T>::heapify()
{
	for (int i = 0; i < _curr_size; i++)
	{
		int parent = get_index_parent(i);
		if (*_heap_array[i] > * _heap_array[parent])
			switch_data(i, parent);		
	}
}

template<typename T>
inline void Max_heap<T>::heapify_from_index(int index)
{
	while (true)
	{
		int parent = get_index_parent(index);
		if (parent == index || *_heap_array[index] < *_heap_array[parent])
			return;
		switch_data(index, parent);
		index = parent;
	}
}
