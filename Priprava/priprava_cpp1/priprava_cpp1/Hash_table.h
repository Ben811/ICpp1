#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include "Data_structure_exception.h"


struct Node;
struct Key_hash;
template<typename K, typename V>
class Hast_table
{
public:
	Hast_table();
	~Hast_table();

	V* get(const K& key);
	void put(const K& key, const V& value);
	void remove(const K& key);
	
private:
	Node** _table;
	Key_hash<_table_size> _function;
	int _table_size;
	
	struct Node
	{
		Node(K key, V data) : _key(key), _value(data), _next(nullptr){}
		K _key;
		V _value;
		//next node with same data
		Node* _next;
	};

	//function to return hash
	template <size_t tablesize>
	struct Key_hash
	{
		unsigned long operator()(const K &key)const
		{
			return reinterpret_cast<unsigned long>(key) % tablesize;
		}
	};
};


template<typename K, typename V>
inline Hast_table<K, V>::Hast_table()
{
	_table_size = 10;
	_table = new Node * [_table_size];
}

template<typename K, typename V>
inline Hast_table<K, V>::~Hast_table()
{
	for (int i = 0; i < _table_size; i++)
	{
		Node* entry = _table[i];

		while(entry != nullptr)
		{
			Node* prev = entry;
			entry = entry->_next;
			delete prev;
		}
		delete[] _table;
	}
} 

template<typename K, typename V>
inline V* Hast_table<K, V>::get(const K& key)
{
	auto hash_value = _function(key);
	Node* entry = _table[hash_value];
	
	while (entry != nullptr)
	{
		if (entry->_key == key)
		{
			return &(entry->_data);
		}
		entry = entry->_next;
	}
	throw Data_structure_exception("Get: data not found");
}

template<typename K, typename V>
inline void Hast_table<K, V>::put(const K& key, const V& value)
{
	auto hash_value = _function(key);
	Node* prev = nullptr;
	Node* entry = _table[hash_value];

	//if the value on the specific hash_value index exists->
	//get to the 
	while (entry != nullptr && entry->_key != key)
	{
		prev = entry;
		entry = entry->_next;
	}

	//if the entry does not exist
	if (entry == nullptr)
	{
		entry = new Node(key, value);

		if (prev == nullptr)
			//insert as first value
			_table[hash_value] = entry;
		
		else
			prev->_next = entry;
		
	}
	else 
		entry->_data = value; //update 
	
}

template<typename K, typename V>
inline void Hast_table<K, V>::remove(const K& key)
{
	auto hash_value = _function(key);
	Node* prev = nullptr;
	Node* entry = _table[hash_value];

	while (entry != nullptr && entry->_key != key)
	{
		prev = entry;
		entry = entry->_next;
	}

	if (entry == nullptr)
		throw Data_structure_exception("Remove: key not found");
	else
	{
		if (prev == nullptr)
			_table[hash_value] = entry->_next;

		else
			prev->_next = entry->_next;

		delete entry;
	}
}
#endif