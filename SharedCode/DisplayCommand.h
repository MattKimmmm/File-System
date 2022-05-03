#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSysPtr;
public:
	DisplayCommand(AbstractFileSystem* fileSys);

	int execute(std::string input) override;
	void displayInfo() override;
};


