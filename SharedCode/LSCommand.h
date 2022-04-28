#pragma once


#include <iostream>

#include "AbstractCommand.h"

class LSCommand: public AbstractCommand {

public:
	int execute(std::string intput) override;
	void displayInfo() override;
};