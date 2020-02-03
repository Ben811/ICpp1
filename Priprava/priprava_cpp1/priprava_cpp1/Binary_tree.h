#ifndef  _BINARY_TREE_H
#define _BINARY_TREE_H

template<typename T>
class Binary_tree_array
{
public:
	Binary_tree_array();
	~Binary_tree_array();
	void insert(T* data);
	T* read();
	void remove(T* data);

	bool empty();
	int get_capacity();
	int get_curr_size();	
private:
	void resize_tree();
	int get_index_parent(int index_child) { return (index_child - 1) / 2; }
	int get_index_left(int index_parent) { return 2 * index_parent + 1; }
	int get_index_right(int index_parent) { return 2 * index_parent + 2; }
	void switch_data(int index1, int index2);

	void repair_tree();
	
	T** _tree_array;

	int _capacity;
	int _curr_size;
	int _repair_rate;
	
};

#endif