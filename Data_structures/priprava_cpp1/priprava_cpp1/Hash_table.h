#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include "Data_structure_exception.h"
#include <sstream>
//template <int tablesize>
//struct Key_hash;

template<typename K, typename V>
class Hast_table
{
public:
	Hast_table();
	~Hast_table();

	V* get(const K& key);
	void put(const K& key, V& value);
	void remove(const K& key);
	std::string to_string();
private:

	struct Node
	{
		Node(K key, V data) : _key(key), _value(data), _next(nullptr) {}
		K _key;
		V _value;
		//_next node with same data
		Node* _next;
	};

	//function to return hash
	
	template<typename K,size_t tablesize>
	struct Key_hash
	{
		unsigned long operator()(const K& key) const
		{
			return static_cast<unsigned long>(key) % tablesize;
		}
	};
	
	
private:
	Node** _table;
	Key_hash<K,10> _function;
	int _table_size;
	
	Node* find_last(Node* node);
	

};


template<typename K, typename V>
inline Hast_table<K, V>::Hast_table()
{
	_table_size = 10;
	_table = new Node * [_table_size];
	for (int i = 0; i < _table_size; i++)
		_table[i] = nullptr;
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
			if (entry->_next != nullptr)
			{
				entry = entry->_next;
			}
			
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
			return &(entry->_value);
		}
		entry = entry->_next;
	}
	return nullptr;
}

template<typename K, typename V>
inline void Hast_table<K, V>::put(const K& key, V& value)
{
	auto hash_value = _function(key);
	auto node = _table[hash_value];

	Node* nextNode = new Node(key, value);
	if (node != nullptr)
	{
		while (node->_next != nullptr && node->_key != key)
		{
			node = node->_next;
		}
		
		if (node->_key == key)
		{
			node->_value = value;
		}
		else
		{
			node->_next = nextNode;
		}
	}
	else
	{
		_table[hash_value] = nextNode;
	}

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
template<typename K, typename V>
inline std::string Hast_table<K, V>::to_string()
{
	std::string ret;
	std::stringstream ss;
	for (int i = 0; i < _table_size; i++)
	{
		Node* temp = _table[i];		
		while(temp != nullptr)
		{
			ss << "index: " << i << " Key: "<< temp->_key << " value: " << temp->_value << std::endl;
			temp = temp->_next;
		}
			
	}
	ret.assign(ss.str());

	
	return ret;
}

template <typename K, typename V>
typename Hast_table<K, V>::Node* Hast_table<K, V>::find_last(Node* node)
{
	if (node != nullptr)
	{
		Node* temp = node;
		while (temp->_next != nullptr)
			temp = temp->_next;
		return temp;
	}
	return nullptr;
}
#endif
