// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>


using namespace std;


int main()
{
	TextFile f1("File1");

	vector<char> cont = { 'a','b','c','d'};

	vector<char> more = { 'e','f' };

	f1.write(cont);

	f1.read();

	f1.getName();

	f1.append(more);

	f1.read();

	return 0;
}


