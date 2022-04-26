
#include "TouchCommand.h"
#include <iostream>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"


using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fileSys, AbstractFileFactory* fileFac) :fileSysPtr(fileSys), fileFacPtr(fileFac){
};

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invokes with command: touch <filename>" << endl;
};


int TouchCommand::execute(string input) {
	AbstractFile * filePtr = fileFacPtr->createFile(input);

	if (filePtr == nullptr) {
		return fileCreationFailure;

	}
	else {
		int tempReturn = fileSysPtr->addFile(input, filePtr);
		if (tempReturn != successful) {
			delete filePtr;
			return fileAlreadyExist;
		}
		return successful;
	}
};