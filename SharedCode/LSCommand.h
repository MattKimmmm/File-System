#pragma once


#include <iostream>

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand: public AbstractCommand {
private:
	AbstractFileSystem* fileSysPtr;
	
public:
	LSCommand(AbstractFileSystem* fileSys);

	int execute(std::string input) override;
	void displayInfo() override;
};