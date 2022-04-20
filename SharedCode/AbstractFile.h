#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>


class AbstractFile {
public:

	virtual ~AbstractFile() = default;

	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> v) = 0;
	virtual int append(std::vector<char> v) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;

};