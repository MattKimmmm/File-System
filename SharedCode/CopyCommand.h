#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSysPtr;

public:
	CopyCommand(AbstractFileSystem* fileSys);

	int execute(std::string input) override;
	void displayInfo() override;
};