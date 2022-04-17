// define methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"

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