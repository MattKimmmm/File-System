#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include <map> 
#include <set>


enum returnCode {
	successful,
	fileAlreadyExist,
	nullFilePtr,
	unknownFileType,
	fileAlreadyOpen,
	fileNotOpen,
	fileNotExist,
	notSupported,
	sizeMismatch,
	emptyImage, 
	noWriteAccess,
	noAppendAccess,
	addCommandFailure,
	userQuit,
	commandNotFound,
	fileCreationFailure
};

class SimpleFileSystem : public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> files;
	set<AbstractFile*> openFiles;


public:
	
	virtual int addFile(std::string fileName, AbstractFile* filePtr) override;
	//virtual int createFile(std::string fileName) override;
	virtual int deleteFile(std::string fileName) override;
	virtual AbstractFile* openFile(std::string fileName) override;
	virtual int closeFile(AbstractFile* filePtr) override;

	virtual set<std::string> getFileNames() override;
	




};