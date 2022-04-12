#pragma once
// Image file class declaration here

#include "AbstractFile.h"
#include <vector>

class ImageFile : public AbstractFile {
	
	std::string name;
	std::vector<char> contents;
	char size;

	
public:

	ImageFile(std::string fileName);

	virtual unsigned int getSize() override;

	virtual std::string getName() override;

	virtual int write(std::vector<char> v) override;

	virtual int append(std::vector<char> v) override;

	virtual void read() override;

};

enum returnCode{
	success,
	failure,
	notSupported
};