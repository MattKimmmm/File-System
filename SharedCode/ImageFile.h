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

};