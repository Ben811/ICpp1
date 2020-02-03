#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

template<typename T>
class Binary_search_tree
{
public:
	
private:
	struct Node
	{
		Node(T* data);
		T* data;
		
		Node* left;
		Node* right;
	};
};

#endif
