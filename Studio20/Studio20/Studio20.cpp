// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/PasswordProxy.h"
#include <iostream>

using namespace std;

int main()
{

	AbstractFile* file1 = new TextFile("Hooray");

	PasswordProxy pwp = PasswordProxy(file1, "understand");

	vector<char> word = { 'e', 'p','w' };
	pwp.write(word);

	for (auto i : pwp.read()) {
		cout << i;
	}

	cout << endl;


	

	delete file1;

	return 0;
}

