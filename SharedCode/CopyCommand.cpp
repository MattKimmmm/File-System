#include "CopyCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "AbstractFileFactory.h"

#include "SimpleFileSystem.h"
#include "PasswordProxy.h"

using namespace std;

class AbstractFileSystem;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) :fileSysPtr(fileSys) {
};

int CopyCommand::execute(string input) {
	string srcFile, copyFileName, fileType;
	istringstream iss = istringstream(input);
	if (!(iss >> srcFile) || !(iss >> copyFileName)) { displayInfo(); return notSupported; }

	set<string> fileNames = fileSysPtr->getFileNames();

	if (fileNames.find(srcFile) == fileNames.end()) {
		cout << "File you are trying to copy does not exist" << endl;
		return fileNotExist;
	}

	size_t pos = srcFile.find(".");
	fileType = srcFile.substr(pos);

	copyFileName += fileType;

	if (fileNames.find(copyFileName) != fileNames.end()) {
		cout << "A new copied file you are trying to create already exists" << endl;
		return fileAlreadyExist;
	}

	AbstractFile* editFile = fileSysPtr->openFile(srcFile);
	AbstractFile* cpyFilePtr = editFile->clone(copyFileName);

	int addedFile = fileSysPtr->addFile(cpyFilePtr->getName(), cpyFilePtr);
	if (addedFile != successful) {
		cout << "Failure to add the copy to the file system. The created copy will be deleted." << endl;
	}
	fileSysPtr->closeFile(editFile);
	
	vector<char> dis = cpyFilePtr->read();
	return addedFile;
}

void CopyCommand::displayInfo() {
	cout << "cp copies files, can be invoked with cp <filename> <new_name_without_extension>" << endl;
};