// define methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;


SimpleFileSystem::~SimpleFileSystem() {
	for (auto i : files) {
		delete i.second;
	}

}

int SimpleFileSystem::addFile(string fileName, AbstractFile* filePtr) {
	if (files.find(fileName) == files.end()) {
		if (filePtr != nullptr) {
			files.insert(make_pair(fileName, filePtr));

			return successful;
		} 
		else {
			return nullFilePtr;
		}
		
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

		return successful;

	}

}

int SimpleFileSystem::deleteFile(string fileName) {

	if (files.find(fileName) == files.end()) {

		return fileNotExist;
	}
	else {

		AbstractFile* filePtr = files.find(fileName) ->second;

		if (openFiles.find(filePtr) == openFiles.end()) {

			files.erase(fileName);

			delete filePtr;

			return successful;
		}
		else {
			return fileAlreadyOpen;
		}


	}
}

set<string> SimpleFileSystem::getFileNames() {

	set<string> fnames;

	for (auto i : files) {
		fnames.insert(i.first);
	}

	return fnames;}