// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"
#include <vector>

#include <iostream>

using namespace std;


int main()
{

	AbstractFile* file1 = new TextFile("Sky");
	AbstractFile* file2 = new ImageFile("Nebula");

	vector<char> v1 = file1->read();

	vector<char> v2 = file2->read();

	v2 = { 'a','d','e','o','2' };

	file2->write(v2);

	for (auto it : v2) {
		cout << it << " ";
	}

	cout << endl;



	delete file1;

	return 0;
}
