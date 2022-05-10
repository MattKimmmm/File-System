
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

		//Test if the file passed in is already read-only (i.e. ChmodProxy object)
		ChmodProxy* chmodPtr = dynamic_cast<ChmodProxy*>(absfilePtr);
		
		if (chmodPtr != nullptr) {
			//The passed in file is read-only, so nothing need to be done
			return successful;
		}


		AbstractFile* fPtr = fileFacPtr->createFile(fileName);

		if (fPtr == nullptr) {
			return fileCreationFailure;

		}
		else {
			//USE password Proxy to created a password-protected file
			try {
				AbstractFile* pwp = new PasswordProxy(fPtr, password);

				int tempReturn = fileSysPtr->addFile(fileName, pwp);
				if (tempReturn != successful) {
					delete fPtr;
					return fileAlreadyExist;
				}
				return successful;
			}
			catch (bad_alloc) {
				cout << "Bad allocation--file creation failture" << endl;
				return badAllocation;
			}

		}


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