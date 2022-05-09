
#include "RenameParsingStrategy.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) {
	vector<string> output;
	output.push_back(input);

	istringstream iss(input);
	string temp,fileType;
	iss >> temp;
	output.push_back(temp);
	return output;
}

