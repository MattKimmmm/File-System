#pragma once

#include <vector>
#include "AbstractFile.h"


class PasswordProxy : public AbstractFile {

public:
	std::vector<char> read() override;
		
	int write(std::vector<char> v) override;
	int append(std::vector<char> v) override;
	unsigned int getSize() override;
	std::string getName() override;

};