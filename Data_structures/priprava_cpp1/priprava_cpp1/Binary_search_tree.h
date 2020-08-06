#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#
#include <compare>
#include "Quicksort.h"
#include <vector>

//key class needs to implement operator "<=>" overload
template<typename Key = int, typename Value = int>
 class Binary_search_tree
{
public:
	Binary_search_tree();
	Binary_search_tree(int repair_rate, int init_capacity);
	~Binary_search_tree();
	
	void insert(Key& key, Value& value);
	Value& read(const Key& key);
	void remove(const Key& key); //soft remove

	bool empty();
	int get_capacity();
	int get_curr_size();
private:
	struct Node
	{
		Node(Key& key, Value& value) : _key(key), _value(value), _isDeleted(false) {}
		Value& _value;
		const Key& _key;
		bool _isDeleted;		
	};

	std::vector<Node*> _tree_array;

	//indicates on how many "soft" deletes the array will be repaired
	int _repair_rate;
	const int DEFAULT_REPAIR_RATE = 5;
	int _capacity;
	const int DEFAULT_CAPACITY = 100;
	int _curr_size;


	void resize_tree();
	int get_index_parent(int index_child) { return (index_child - 1) / 2; }
	int get_index_left(int index_parent) { return 2 * index_parent + 1; }
	int get_index_right(int index_parent) { return 2 * index_parent + 2; }
	void switch_data(int index1, int index2);

	void repair_tree();

	int find_node_index(const Key& key);
};

#endif

 template<typename Key, typename Value>
 inline Binary_search_tree<Key, Value>::Binary_search_tree()
	 : Binary_search_tree(DEFAULT_REPAIR_RATE, DEFAULT_CAPACITY)
 {	 
 }

 template<typename Key, typename Value>
 inline Binary_search_tree<Key, Value>::Binary_search_tree(int repair_rate, int init_capacity)
 {
	 _repair_rate = repair_rate;
	 _curr_size = 0;
	 _capacity = init_capacity;

	 _tree_array.reserve(init_capacity);
 }

 template<typename Key, typename Value>
 inline Binary_search_tree<Key, Value>::~Binary_search_tree()
 {
	 for (int i = 0; i < _capacity; i++)
	 {
		 if (_tree_array[i] != nullptr)
			 delete _tree_array[i];
	 }
 }

 template<typename Key, typename Value>
inline void Binary_search_tree<Key, Value>::insert(Key& key, Value& value)
{
	int index = find_node_index(key);

	Node* new_node = new Node(key, value);	

	_tree_array[index] = new_node;
	_curr_size++;
}

template<typename Key, typename Value>
inline Value& Binary_search_tree<Key, Value>::read(const Key& key)
{
	int index = find_node_index(key);
	return _tree_array[index]->_value;
}

template<typename Key, typename Value>
inline void Binary_search_tree<Key, Value>::remove(const Key& key)
{
	int index = find_node_index(key);
	if (_tree_array[index] != nullptr)
	{
		_tree_array[index]->_isDeleted = true;
	}
}

template<typename Key, typename Value>
inline bool Binary_search_tree<Key, Value>::empty()
{
	return _curr_size == 0;
}

template<typename Key, typename Value>
inline int Binary_search_tree<Key, Value>::get_capacity()
{
	return _capacity;
}

template<typename Key, typename Value>
inline int Binary_search_tree<Key, Value>::get_curr_size()
{
	return _curr_size;
}

template<typename Key, typename Value>
inline void Binary_search_tree<Key, Value>::resize_tree()
{
	int old_capacity = _capacity;
	_capacity *= 2;
	_tree_array.resize(_capacity);
}

template<typename Key, typename Value>
inline void Binary_search_tree<Key, Value>::switch_data(int index1, int index2)
{
	Node* temp = _tree_array[index1];
	_tree_array[index1] = _tree_array[index2];
	_tree_array[index2] = temp;
}

template<typename Key, typename Value>
inline void Binary_search_tree<Key, Value>::repair_tree()
{

}


template<typename Key, typename Value>
inline int Binary_search_tree<Key, Value>::find_node_index(const Key& key)
{
	int index = 0;
	Node* cruise_node = _tree_array[index];

	while (cruise_node != nullptr)
	{
		if (cruise_node->_key > key)
		{
			index = get_index_left(index);
			cruise_node = _tree_array[index];
		}
		else
		{
			index = get_index_right(index);
			cruise_node = _tree_array[index]; 
		}
	}
	return index;
}