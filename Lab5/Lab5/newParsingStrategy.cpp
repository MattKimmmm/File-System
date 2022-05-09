#include "newParsingStrategy.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> newParsingStrategy::parse(string input) {

	vector<string> output;
	string fileName, flag;
	istringstream iss(input);
	iss >> fileName;
	if (iss >> flag) {
		if (flag == "-p") {
			output.push_back(input);
			output.push_back(fileName);
		}
		
		
	}
	else {

	}

	output.push_back(input);
	output.push_back(input);
	return output;
}