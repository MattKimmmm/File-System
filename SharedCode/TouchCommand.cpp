
#include "TouchCommand.h"
#include <iostream>
#include <sstream>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"


using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fileSys, AbstractFileFactory* fileFac) :fileSysPtr(fileSys), fileFacPtr(fileFac){
};

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invokes with command: touch <filename> [-p]" << endl;
	cout << "-p creates a file protected by password" << endl;
};


int TouchCommand::execute(string input) {

	//If the arguments passed in after touch is single (no spaces)
	//Creates a file without password protection
	if (input.find(" ") == -1) {

		AbstractFile* filePtr = fileFacPtr->createFile(input);

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

	}
	//There is a space in the arguments passed in (makes the argument possibly -p)
	else {
		string fileName, flag, password;
		istringstream iss = istringstream(input);

		//Extract two arguments for LSCommand
		if(iss >>fileName){}
		else {
			//Unnecessary return statement???
			return fileCreationFailure;
		}
		if (iss >> flag) {}
		else {
			//Unnecessary return statement???
			return fileCreationFailure;
		}

		//Chek if the user asks for password-protected file
		if (flag == "-p") {

			cout << "What is the password?" << endl;
			//cin >> password;
			getline(cin, password);

			
			AbstractFile* fPtr = fileFacPtr->createFile(fileName);

			if (fPtr == nullptr) {
				return fileCreationFailure;

			}
			else {
				//USE password Proxy to created a password-protected file

				AbstractFile* pwp = new PasswordProxy(fPtr, password);

				int tempReturn = fileSysPtr->addFile(fileName, pwp);
				if (tempReturn != successful) {
					delete fPtr;
					return fileAlreadyExist;
				}
				return successful;
			}


		}
		else {
			return commandNotFound;
		}


	}


	

	
};