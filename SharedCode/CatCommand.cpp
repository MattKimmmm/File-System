#include "CatCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys) :fileSysPtr(fileSys) {
};

int CatCommand::execute(string input) {
	if (input.find(" ") == -1) {
		string fileName, fileType, userInput;
		istringstream iss = istringstream(input);
		if (!(iss >> fileName)) { return notSupported; }

		size_t pos = fileName.find(".");
		fileType = fileName.substr(pos);
	
		AbstractFile* editFile = fileSysPtr->openFile(fileName);
		if (editFile == nullptr) {
			return fileNotExist;
		}

		vector<char> overwriteContent = {}; //contents to overwrite to file.

		//Print statement to guide user about using catCommand
		cout << endl;
		cout << "Enter data you would like to write to the file. Enter :wq to sace the file and exit,"
			<< " enter :q to exist without saving and without saving and without -a, we don't append but overwrite the old contents" << endl;

		
		while (true) {

			
			getline(cin,userInput);
			if (!(userInput == ":wq") && !(userInput == ":q")) {
				string contentInput;
				stringstream temp(userInput);
				getline(temp, contentInput);
				for (int i = 0; i < userInput.length(); ++i) {
					overwriteContent.push_back(contentInput.at(i));
				}
				overwriteContent.push_back('\n'); ///diff for img
			}
			else {
				if (userInput == ":q") {
					fileSysPtr->closeFile(editFile);
					return successful;
				}
				else if (userInput == ":wq") {
					overwriteContent.pop_back();
					int edit = editFile->write(overwriteContent);
					overwriteContent.clear();
					fileSysPtr->closeFile(editFile);

					return edit;
				}
			}
		}
	}
	else {
		string fileName, flag, fileType, userInput;
		istringstream iss = istringstream(input);
		if (!(iss >> fileName) || !(iss >> flag)){ return notSupported; }
		
		if (flag == "-a") {
			size_t pos = fileName.find(".");
			fileType = fileName.substr(pos);
			vector<char> appendContent = {}; //contents to append to file.
			
			AbstractFile* editFile = fileSysPtr->openFile(fileName);

			if (fileType == ".img") {
				int edit = editFile->append(appendContent);
				fileSysPtr->closeFile(editFile);
				return edit;
			}

			vector<char> contents = editFile->read();
			for (char c : contents) {
				cout << c;
			}
			cout << endl;

			while (true) {
				getline(cin, userInput);
				if (!(userInput == ":wq") && !(userInput == ":q")) {
					string contentInput;
					stringstream temp(userInput);
					getline(temp, contentInput);
					for (int i = 0; i < userInput.length(); ++i) {
						appendContent.push_back(contentInput.at(i));
					}
					appendContent.push_back('\n');
				}
				else {
					if (userInput == ":q") {
						fileSysPtr->closeFile(editFile);
						return successful;
					}
					else if (userInput == ":wq") {
						appendContent.pop_back();
						int edit = editFile->append(appendContent);
						fileSysPtr->closeFile(editFile);

						return edit;
					}
				}
				

			}
		}
		else {
			displayInfo();
			return commandNotFound;
		}
	}
	return notSupported;

};

void CatCommand::displayInfo() {
	cout << "-a lists the content of files, can be invoked with cat <filename> -a" << endl;
};