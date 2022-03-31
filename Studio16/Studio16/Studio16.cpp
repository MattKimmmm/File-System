// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>


using namespace std;


int main()
{
	AbstractFile * f1 = new TextFile("File1");//Need to create a heap resource

	vector<char> cont = { 'a','b','c','d' };

	vector<char> more = { 'e','f' };

	f1->write(cont);

	f1->read();

	

	f1->getName();

	//cout << "Got name" << endl;

	f1->append(more);
	
	f1->read();

	delete f1;

	return 0;
}


