	


#include <iostream>
#include "Hash_table.h"

#include "Min_heap.h"
#include "Test_entity.h"
#include "Max_heap.h"
#include "Doubly_linked_list.h"
#include "Single_linked_list.h"

int main(int argc, char* argv[]) 
{
	try
	{
		Hast_table<double, Test_entity> a{};

		for (int i = 0; i < 1; i++)
		{
			Test_entity first_in_hash(i+1);
			Test_entity second_in_hash(i+11);
			Test_entity third_in_hash(i+111);
					
			a.put(i+0.1, first_in_hash);
			a.put(i+0.01, second_in_hash);
			a.put(i + 0.001, third_in_hash);
		}
		Test_entity* temp =  a.get(0.0001);
		std::string ret = a.to_string();
		std::cout << ret << std::endl;

		
	}
	catch (Data_structure_exception& ex)
	{
		std::cerr << ex.what();
	}
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}

