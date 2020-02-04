	


#include <iostream>
#include <sstream>
#include "Min_heap.h"
#include "Test_entity.h"
#include "Max_heap.h"
#include "Doubly_linked_list.h"
#include "Single_linked_list.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	try
	{
		Single_linked_list<Test_entity> a{};
		for (int i = 0; i < 10; i++)
		{			
			a.append(new Test_entity(i));
		}

		a.insert_at(3,new Test_entity(21));
		a.insert(new Test_entity(10));
		a.delete_list();
		string vypis = a.to_string();
		cout << vypis;
	}
	catch (Data_structure_exception& ex)
	{
		std::cerr << ex.what();
	}
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}

