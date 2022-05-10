
//#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "SimpleFileSystem.h"
#include "ChmodProxy.h"
#include "ChmodCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

class AbstractFileSystem;

int ChmodCommand::execute(std::string input) {




	string fileName, flag;
	istringstream iss = istringstream(input);

	//Extract two arguments for ChmodCommand
	if (!(iss >> fileName) || !(iss >> flag)) { 
		cout << "Incorrect command syntax" << endl;
		displayInfo();
		return notSupported; }

	//Check if the user asks for making the file read-only
	if (flag == "-") {

		AbstractFile* absfilePtr = fileSys->openFile(fileName);
		//Check if the file exists
		if (absfilePtr == nullptr) {
			cout << "File not found" << endl;
			return notSupported;
		}

		fileSys->closeFile(absfilePtr);

		//Test if the file passed in is already read-only (i.e. ChmodProxy object)
		ChmodProxy* chmodPtr = dynamic_cast<ChmodProxy*>(absfilePtr);
		
		if (chmodPtr == nullptr) {
			//The file passed in is writable, need to make it read-only

			//Creates a new file resource using ChmodProxy, delete the old one, fileName stays the same
			AbstractFile* tempCopy = absfilePtr->clone(fileName);
			//Check for bad allocation
			if (tempCopy == nullptr) {
				return badAllocation;
			}
			else {
				//If clone is successful
				fileSys->deleteFile(fileName);

				//Create ChmodProxy object and add to fileSystem
				try{
					ChmodProxy* readOnly = new ChmodProxy(tempCopy);
					int retCode = fileSys->addFile(fileName, readOnly);

				
					//Check if file is added to the fileSys successfully
					if (retCode != successful) {
						return fileCreationFailure;
					}
					else {
						return successful;
					}
				}
				catch (bad_alloc) {
					return badAllocation;
				}
				
			}

		
		}
		else {
			//The file passed in is already read-only, so nothing need to be done
			return successful;
		}




		
	}

	//The user wants make a file writable

	//IF the file is already writable, do nothing and return successs
	// check if chmodproxy* chmodproxy = dynamic_cast <chmodproxy *> (fileptr that user passed in) is nullptr
	//If so, the file is already writable
	//Else
	//    make the file writa ble
	// one way to do it is to make a clone of current chmod proxy obejct, and add the filePtr of cloned object to the filesystem
	//delete the original chmodproxy object from the system.
	else if (flag == "+") {

	}
	else {
		return commandNotFound;
	}


	

};


void ChmodCommand::displayInfo() {
	cout << "chmod changes the file to and from read-only, chmod <file_name> - makes the file read-only, " <<
		" and chmod <file_name> + makes the file writable again" << endl;
};

ChmodCommand::ChmodCommand(AbstractFileSystem* sys):fileSys(sys) {
};