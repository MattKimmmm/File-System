#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSysPtr;
public:
	CatCommand(AbstractFileSystem* fileSys);

	int execute(std::string input) override;
	void displayInfo() override;
};


