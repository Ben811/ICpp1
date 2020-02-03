	


#include <iostream>
#include <sstream>
#include "Min_heap.h"
#include "Test_entity.h"
#include "Max_heap.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	try
	{
		Max_heap<Test_entity> heap{};
		Min_heap<Test_entity> heap1{};
		heap.insert(new Test_entity(111));
		heap.insert(new Test_entity(50));
		heap.insert(new Test_entity(49));
		heap.insert(new Test_entity(30));
		heap.insert(new Test_entity(31));
		heap.insert(new Test_entity(25));
		heap.insert(new Test_entity(20));
		heap.insert(new Test_entity(0));
		heap.insert(new Test_entity(11));
		heap.insert(new Test_entity(1));
		heap.insert(new Test_entity(0));

		stringstream ss;
		string s;
		int velikost = heap.get_size();
		ss << "velikost max_heapu: " << to_string(velikost) << endl;
		for (int i = 0; i < velikost; i++)
		{
			Test_entity* temp = heap.remove_max();
			ss << *temp << endl;
			heap1.insert(temp);
		}
		s.assign(ss.str());
		cout << s << endl;
		stringstream ss1;
		string s1;
		velikost = heap1.get_size();
		ss1 << "velikost min_heapu: " << to_string(velikost)<< endl;
		for (int i = 0; i < velikost; i++)
		{
			Test_entity* temp = heap1.remove_min();
			ss1 << *temp << endl;
			delete temp;
		}
		s1.assign(ss1.str());
		cout << s1 << endl;
	}
	catch (Data_structure_exception& ex)
	{
		std::cerr << ex.what();
	}
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}

