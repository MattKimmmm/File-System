// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SimpleFileSystem.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>

using namespace std;
//#include "ImageFile.h"


int main()
{
	SimpleFileSystem fSys;

	TextFile txtFile1 = TextFile("sample");
	TextFile txtFile2 = TextFile("superstar");

	ImageFile imgFile1 = ImageFile("bison");
	ImageFile imgFile2 = ImageFile("chondrite");

	fSys.addFile("sample", &txtFile1);
	fSys.addFile("bison", &imgFile1);

	fSys.createFile("tangerine.img");
	fSys.createFile("oneLine.txt");
	fSys.createFile("bomb.abc");

	AbstractFile * ptr = fSys.openFile("sample");

	fSys.closeFile(ptr);

	vector<char> input = { 'a','b','e','3' };
	txtFile1.write(input);





	return 0;
}

