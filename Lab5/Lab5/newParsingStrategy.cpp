#include "newParsingStrategy.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> newParsingStrategy::parse(string input) {

	vector<string> output;
	output.push_back(input);
	output.push_back(input);
	return output;
}