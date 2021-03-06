#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H
#include <string>
#include <sstream>

//if i want to use this, i need to overload operator<< for the
//data, i want to use inside each node

template<typename Value>
class Doubly_linked_list
{
public:
	Doubly_linked_list();
	~Doubly_linked_list();
	void append(Value* value);
	void insert(Value* value);
	void insert_at(int index, Value* value);
	void delete_first();
	void delete_last();
	void delete_at(int index);
	Value* read(int index);
	int get_size();
	std::string to_string();
	void delete_list();
private:
	struct Node
	{
		Node(Value* data) { _data = data; _next = nullptr; _prev = nullptr; }
		~Node() { delete _data; }
		Value* _data;
		Node* _next;
		Node* _prev;
		friend std::ostream& operator<<(std::ostream& os, const Node& node) { os << *(node._data); return os; }
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
};

#endif

template<typename Value>
inline Doubly_linked_list<Value>::Doubly_linked_list(): _size(0), _first(nullptr), _last(nullptr){ }

template<typename Value>
inline Doubly_linked_list<Value>::~Doubly_linked_list()
{
	delete_list();
}

template<typename Value>
inline void Doubly_linked_list<Value>::append(Value* value)
{
	Node* temp = new Node(value);
	if (_size == 0)
	{
		_first = temp;
		_last = temp;
	}
	else
	{
		_last->_next = temp;
		temp->_prev = _last;
		
		_last = temp;
	}
	_size++;
}

template<typename Value>
inline void Doubly_linked_list<Value>::insert(Value* value)
{
	Node* temp = new Node(value);
	if (_size == 0)
	{
		_first = temp;
		_last = temp;
	}
	else
	{
		_first->_prev = temp;
		temp->_next = _first;
		
		_first = temp;
	}
	_size++;
}

template<typename Value>
inline void Doubly_linked_list<Value>::insert_at(int index, Value* value)
{
	if (index == 0)
	{
		insert(value);
	}
	else if(index == _size)
	{
		append(value);
	}
	else if (index < _size)
	{
		Node* temp = find_node(index);
		Node* new_node = new Node(value);

		new_node->_next = temp;
		new_node->_prev = temp->_prev;

		temp->_prev->_next = new_node;
		temp->_prev = new_node;		
		_size++;
	}
	else
	{
		throw Data_structure_exception("Insert_at: index is out of range");
	}
}

template<typename Value>
inline void Doubly_linked_list<Value>::delete_first()
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
		throw Data_structure_exception("delete_first: _first is nullptr");
	}

}

template<typename Value>
inline void Doubly_linked_list<Value>::delete_last()
{
	if (_last != nullptr)
	{
		Node* temp = _last;
		_last = _last->_prev;
		delete temp;
		_size--;
	}
	else
	{
		throw Data_structure_exception("delete_last: _last is nullptr");
	}
}

template<typename Value>
inline void Doubly_linked_list<Value>::delete_at(int index)
{
	if (index == 0)
	{
		delete_first();
	}
	else if ( index == _size-1)
	{
		delete_last();
	}
	else if (index < _size)
	{
		Node* temp = find_node(index);
		temp->_prev->_next = temp->_next;
		delete temp;
		_size--;
	}
	else
	{
		throw Data_structure_exception("delete_at: index is out of range");
	}
}


template<typename Value>
inline Value* Doubly_linked_list<Value>::read(int index)
{
	if (index < _size)
	{
		Node* temp = find_node(index);
		return &(temp->_value);
	}
	else
	{
		throw Data_structure_exception("delete_at: index is out of range");
	}

	
}

template<typename Value>
inline int Doubly_linked_list<Value>::get_size()
{
	return _size;
}

template<typename Value>
inline std::string Doubly_linked_list<Value>::to_string()
{
	if (_size > 0)
	{
		std::string ret_string;
		std::stringstream ss;
		Node* temp = _first;
		for (int i = 0; i < _size; i++)
		{			
			ss << i << ": " << *temp << std::endl;
			temp = temp->_next;
		}
		ret_string.append(ss.str());
		return ret_string;
	}
	
	return "";
}

template<typename Value>
inline void Doubly_linked_list<Value>::delete_list()
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
