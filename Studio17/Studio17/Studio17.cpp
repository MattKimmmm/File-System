// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\AbstractFile.h"
#include "..\..\SharedCode\TextFile.h"
#include "..\..\SharedCode\ImageFile.h"
#include <vector>
#include <iostream>

using namespace std;
//#include "ImageFile.h"


int main()
{
	SimpleFileSystem fSys;

	TextFile txtFile1 = TextFile("sample");
	TextFile txtFile2 = TextFile("superstar");

	cout << "part 1 finished" << endl;

	ImageFile imgFile1 = ImageFile("bison");
	ImageFile imgFile2 = ImageFile("chondrite");

	cout << "part 2 finished" << endl;

	fSys.addFile("sample", &txtFile1);
	fSys.addFile("bison", &imgFile1);

	cout << "part 3 finished" << endl;

	fSys.createFile("tangerine.img");
	fSys.createFile("oneLine.txt");
	fSys.createFile("bomb.abc");

	AbstractFile * ptr = fSys.openFile("sample");

	fSys.closeFile(ptr);

	vector<char> input = { 'a','b','e','3' };
	txtFile1.write(input);


	vector<char> imgInput = { 'X', 'X' , ' ' , 'X' };


	return 0;
}

