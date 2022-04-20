// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include <vector>

#include <iostream>

using namespace std;


int main()
{

	BasicDisplayVisitor bdv = BasicDisplayVisitor();

	AbstractFile* file1 = new TextFile("Sky");
	AbstractFile* file2 = new ImageFile("Nebula");

	

	vector<char> v2 =  { 'a','d','e','o','2' };

	file1->write(v2);

	file1->accept(&bdv);
	cout << "Accept is called " << endl;


	delete file1;
	delete file2;

	return 0;
}
