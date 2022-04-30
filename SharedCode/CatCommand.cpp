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
		string fileName, userInput;
		istringstream iss = istringstream(input);
		if (!(iss >> fileName)) { return notSupported; }
		AbstractFile* editFile = fileSysPtr->openFile(fileName);
		if (editFile == nullptr) {
			return fileNotExist;
		}
		vector<char> overwriteContent = {}; //contents to overwrite to file.

		while (true) {
			cin >> userInput;
			if (!(userInput == ":wq") && !(userInput == ":q")) {
				string contentInput;
				stringstream temp(userInput);
				getline(temp, contentInput);
				for (int i = 0; i < userInput.length(); ++i) {
					overwriteContent.push_back(contentInput.at(i));
				}
			}
			else {
				if (userInput == ":q") {
					fileSysPtr->closeFile(editFile);
					return successful;
				}
				else if (userInput == ":wq") {
					int edit = editFile->write(overwriteContent);

					vector<char> result = editFile->read();
					for (int i = 0; i < result.size(); ++i) {
						cout << result[i];
					}
					cout << endl;
					fileSysPtr->closeFile(editFile);

					return successful;
				}
				return commandNotFound;
			}
		}
	}
	else {
		string fileName, flag, userInput;
		istringstream iss = istringstream(input);
		if (!(iss >> fileName) || !(iss >> flag)){ return notSupported; }
		
		if (flag == "-a") {
			AbstractFile* editFile = fileSysPtr->openFile(fileName);
			vector<char> contents = editFile->read();
			for (char c : contents) {
				cout << c;
			}
			cout << endl;
			

			vector<char> appendContent = {}; //contents to append to file.
			
			while (true) {
				cin >> userInput;
				if (!(userInput == ":wq") && !(userInput == ":q")) {
					string contentInput;
					stringstream temp(userInput);
					getline(temp, contentInput);
					for (int i = 0; i < userInput.length(); ++i) {
						appendContent.push_back(contentInput.at(i));
					}
				}
				else {
					if (userInput == ":q") {
						fileSysPtr->closeFile(editFile);
						return successful;
					}
					else if (userInput == ":wq") {
						int edit = editFile->append(appendContent);
						
						vector<char> result = editFile->read();
						for (int i = 0; i < result.size(); ++i) {
							cout << result[i];
						}
						cout << endl;
						fileSysPtr->closeFile(editFile);

						return successful;
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