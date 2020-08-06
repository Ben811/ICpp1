#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H
#include <string>
#include <sstream>
#include "Data_structure_exception.h"

//if i want to use this, i need to overload operator<< for the
//data, i want to use inside each node


template<typename Value>
class Single_linked_list
{
public:
	Single_linked_list();
	~Single_linked_list();
	void append(Value* value);//at the end
	void insert(Value* value); //to the front
	void insert_at(int pos, Value* value);
	void delete_first();
	void delete_at(int index);
	Value* read(int index);
	int get_size();
	std::string to_string();
	void delete_list();
private:
	struct Node
	{	
		Node(Value* val) { _value = val; _next = nullptr; }
		~Node() { delete _value; }
		Value* _value;
		Node* _next;
		friend std::ostream& operator<<(std::ostream& os, const Node& node) { os << *(node._value); return os; }
	};
	int _size;
	Node* _first;
	Node* _last;

	Node* find_node(int index) {
		Node* temp = _first;
		for (int i = 0; i < index; i++)
			temp = temp->_next;
		return temp;
	}

	/*
	 * 
	if (node != nullptr)
	{
		Node* temp = node;
		while (temp->_next != nullptr)
			temp = temp->_next;
		return temp;
	}
	return nullptr;
	 */
};

#endif

template<typename Value>
inline Single_linked_list<Value>::Single_linked_list() : _size(0), _first(nullptr), _last(nullptr) {}

template<typename Value>
inline Single_linked_list<Value>::~Single_linked_list()
{
	delete_list();
}

template<typename Value>
inline void Single_linked_list<Value>::append(Value* value)
{
	Node* temp = new Node(value);
	if (_size == 0)
	{
		_first = temp;
		_last = _first;		
	}
	else
	{
		_last->_next = temp;
		_last = _last->_next;	
	}
	_size++;
}

template<typename Value>
inline void Single_linked_list<Value>::insert(Value* value)
{
	Node* temp = new Node(value);
	if (_size == 0)
	{
		_first = temp;
		_last = _first;
	}
	else
	{			
		temp->_next = _first;
		_first = temp;
	}
	_size++;
}

template<typename Value>
inline void Single_linked_list<Value>::insert_at(int pos, Value* value)
{
	if (pos == 0)
	{
		insert(value);
	}
	else if (pos == _size)
	{
		append(value);
	}
	else if(pos < _size)
	{
		Node* temp = find_node(pos - 1);
		Node* new_node = new Node(value);

		new_node->_next = temp->_next;
		temp->_next = new_node;
		_size++;
	}
	else
	{
		throw Data_structure_exception("Insert_at: index is out of range");
	}
}

template<typename Value>
inline void Single_linked_list<Value>::delete_first()
{
	if (_first != nullptr)
	{
		Node* temp = _first;
		_first = _first->_next;
		delete temp;
		_size--;
	}
	else
	{
		throw Data_structure_exception("Delete_first: first is nullptr");
	}
}

template<typename Value>
inline void Single_linked_list<Value>::delete_at(int index)
{
	if (index == 0)
	{
		delete_first();
	}
	else if(index < _size)
	{
		Node* temp = find_node(index-1);
		if (temp->_next == _last)
		{
			delete _last;
			_last = temp;
		}
		else
		{
			Node* del = temp->_next;
			temp->_next = temp->_next->_next;
			delete del;
		}
		_size--;
	}
	else
	{
		throw Data_structure_exception("Delete_at: index is out of range" );
	}
}

template<typename Value>
inline Value* Single_linked_list<Value>::read(int index)
{
	if (index < _size)
	{
		Node* temp = find_node(index);
		return &(temp->_value);
	}
	else
	{
		throw Data_structure_exception("Read: index is out of range");
	}
}

template<typename Value>
inline int Single_linked_list<Value>::get_size()
{
	return _size;
}

template<typename Value>
inline std::string Single_linked_list<Value>::to_string()
{
	if (_size == 0)
	{
		return "";
	}
	std::stringstream ss;
	std::string ret_string;
	
	Node* temp = _first;
	for (int i = 0; i < _size; i++)
	{
		ss << i << ": " << *temp << std::endl;
		temp = temp->_next;
	}	
	ret_string.assign(ss.str());
	return ret_string;
}

template<typename Value>
inline void Single_linked_list<Value>::delete_list()
{
	if (_first != nullptr)
	{
		for (int i = 0; i < _size; i++)
		{
			Node* del = _first;
			_first = _first->_next;
			delete del;
		}
		_size = 0;		
	}
}

