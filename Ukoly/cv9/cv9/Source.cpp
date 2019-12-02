#include "Potrubi.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	
	std::ifstream inFile;
	inFile.open("a.txt"); 

	std::stringstream strStream;
	strStream << inFile.rdbuf(); 
	std::string str = strStream.str();
	
	istringstream* ss = new istringstream(str);
	Potrubi p = Potrubi(ss);

	cout << (p.JePotrubiOk() ? "true" : "false");

	
	return 0;
}