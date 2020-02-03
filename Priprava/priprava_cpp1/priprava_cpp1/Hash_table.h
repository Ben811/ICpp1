#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

template<typename T>
class Hast_table
{
public:
	Hast_table();
private:
	struct Node
	{
		Node(int key, T data) : _key(key), _data(data){}
		int _key;
		T _data;
	};
	Node** _table;
};

#endif
