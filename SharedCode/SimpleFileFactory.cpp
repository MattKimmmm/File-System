// studio 18 - simple file factory definitions
#include <string>
#include <iostream>

#include "SimpleFileFactory.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string fileName) {
	

	size_t pos = fileName.find(".") + 1;
	string fileType = fileName.substr(pos);

	try {
		if (fileType == "txt") {
			TextFile* textFilePtr = new TextFile(fileName);
			return textFilePtr;
		}
		if (fileType == "img") {
			ImageFile* imageFilePtr = new ImageFile(fileName);

			return imageFilePtr;
		}
		cout << "***Unsupported file type" << endl;
		return nullptr;
	}
	catch (bad_alloc) {
		cout << "Bad allocation error, file creation failture" << endl;
		return nullptr;
	}
}