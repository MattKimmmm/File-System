
#include "LSCommand.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include <sstream>
#include <string>
#include <set>
#include <iostream>
#include <iomanip>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fileSys) : fileSysPtr(fileSys) {

};

int LSCommand::execute(string input) {

	set<string> fileList = fileSysPtr->getFileNames();

	//If the command only has one argument, no input string will be passed
	if (input == "") {
		int index = 1;
		int strFormatCons = 20;
		for (auto i: fileList) {
			if (index % 2 == 1) {
				cout << setw(strFormatCons) << left << i ;
			}
			else {
				cout << setw(strFormatCons) << left << i << endl;
			}
			index++;
		}
		cout << endl;
		return successful;
	}
	//if the command is more than one argument, everything but the first argument will be passed to input string
	else if(input == "-m") {
		

		MetadataDisplayVisitor mdv = MetadataDisplayVisitor();

		//Call accept on all files pointers in the file system to use MetaDisplayVisitor
		//Display meta data
		for (auto i : fileList) {
			AbstractFile* filetoOpenPtr = fileSysPtr->openFile(i);
			filetoOpenPtr->accept(&mdv);
			fileSysPtr->closeFile(filetoOpenPtr);
			
		}

		

		return successful;

	}
	else {
		displayInfo();
		return commandNotFound;
	}

}
void LSCommand::displayInfo() {
	cout << "LS lists the name of all files, ls can be invoked with command: ls OR ls -m" << endl;
	cout << "ls -m will list all files with meta data" << endl;
}