// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\AbstractFile.h"
using namespace std;

int main()
{
	vector<char> v = {'a', 'b','c','d'};
	vector<char> imgV = { 'X', ' ', 'X','X', '4'};
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* test2 = new SimpleFileFactory();
	AbstractFile * file1 = test2->createFile("file.txt");
	AbstractFile * file2 = test2->createFile("image.img");
	test->addFile("file.txt",file1);
	test->addFile("image.img", file2);
	AbstractFile* finalFile = test->openFile("file.txt");
	AbstractFile* finalFile2 = test->openFile("image.img");
	finalFile->write(v);
	finalFile->read();
	finalFile2->write(imgV);
	finalFile2->read();

	return 0;
}
