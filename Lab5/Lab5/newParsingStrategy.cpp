#include "newParsingStrategy.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;


//Parsing strategy for Touch + Cat (toc) Macrocommand
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
		output.push_back(fileName);
		output.push_back(fileName);
	}
	
	return output;
}