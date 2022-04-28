#pragma once
// declaration of the interface all file systems provide goes here
#include <string>
#include "AbstractFile.h"
#include <set>


class AbstractFileSystem {
public:

	virtual int addFile(std::string fileName, AbstractFile* filePtr) = 0;
	//virtual int createFile(std::string fileName) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile* filePtr) = 0;

	virtual set<std::string> getFileNames() = 0;

	
};