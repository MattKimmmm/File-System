// define methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile* filePtr) {
	if (files.find(fileName) == files.end()) {
		if (filePtr != nullptr) {
			files.insert(make_pair(fileName, filePtr));

			return success;
		} 
		else {
			return nullFilePtr;
		}
		
	}
	else {
		return fileAlreadyExist;
	}
}

int SimpleFileSystem::createFile(string fileName) {
	if (files.find(fileName) == files.end()) {

		size_t pos = fileName.find(".");
		string fileType = fileName.substr(pos);

		if (fileType == "txt") {
			TextFile* textFilePtr = new TextFile(fileName);

			addFile(fileName, textFilePtr);

			return success;
		}
		if (fileType == "img") {
			ImageFile* imageFilePtr = new ImageFile(fileName);

			addFile(fileName, imageFilePtr);

			return success;
		}

		return unknownFileType;

	}
	else {
		return fileAlreadyExist;
	}
}

AbstractFile* SimpleFileSystem::openFile(string fileName) {
	if (files.find(fileName) == files.end()) {
		return nullptr;
	}
	else {
		AbstractFile* filePtr = files.find(fileName)->second;

		if (openFiles.find(filePtr) == openFiles.end()) {

			openFiles.insert(filePtr);
			
			return filePtr;

		}
		else {
			return nullptr;
		}
	}
}

int SimpleFileSystem::closeFile(AbstractFile* filePtr) {

	if (openFiles.find(filePtr) == openFiles.end()) {
		return fileNotOpen;
	}
	else {

		openFiles.erase(filePtr);

		return success;

	}

}