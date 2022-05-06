#include "CopyCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "AbstractFileFactory.h"

#include "SimpleFileSystem.h"

using namespace std;

class AbstractFileSystem;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) :fileSysPtr(fileSys) {
};

int CopyCommand::execute(string input) {
	string srcFile, copyFile, fileType;
	istringstream iss = istringstream(input);
	if (!(iss >> srcFile) || !(iss >> copyFile)) { return notSupported; }

	size_t pos = srcFile.find(".");
	fileType = srcFile.substr(pos);

	if (fileType == ".txt") {
		AbstractFile* editFile = fileSysPtr->openFile(srcFile);
		AbstractFile* copiedFile = editFile->clone(copyFile);
		int addedFile = fileSysPtr->addFile(copiedFile->getName(), copiedFile);
		vector<char> dis = copiedFile->read();
		return addedFile;
	}
	else if (fileType == ".img") {

	}
	return successful;
}

void CopyCommand::displayInfo() {
	cout << "cp <file_to_copy> <new_name_with_no_exception>" << endl;
}