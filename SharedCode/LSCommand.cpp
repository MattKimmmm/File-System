
#include "LSCommand.h"
#include "SimpleFileSystem.h"
#include <sstream>
#include <string>
#include <set>
#include <iostream>
#include <iomanip>

using namespace std;



int LSCommand::execute(string input) {

	set<string> fileList = fileSysPtr->getFileNames();

	if (input == "ls") {
		int index = 1;
		for (auto i: fileList) {
			if (index % 2 == 1) {
				cout << setw(20) << i;
			}
			else {
				cout << i << endl;
			}
			index++;
		}
		return successful;
	}
	else if(input == "ls -m") {
		//call accept on file pointers to use metaDisplayVisitor



	}
	else {
		displayInfo();
		return commandNotFound;
	}

}
void LSCommand::displayInfo() {

}