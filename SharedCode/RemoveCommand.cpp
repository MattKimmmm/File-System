#include "RemoveCommand.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <string>

using namespace std;


RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fileSysPtr(fileSys) {
}

void RemoveCommand::displayInfo() {
	cout << "Remove removes a file from the system, remove can be invoked with the command: rm <filename>" << endl;
}

int RemoveCommand::execute(string input) {
	
	
	return fileSysPtr->deleteFile(input);
	

}