#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class ChmodCommand : public AbstractCommand {

public:

	ChmodCommand(AbstractFileSystem* sys);

	virtual int execute(std::string intput) = 0;
	virtual void displayInfo() = 0;

private:
	AbstractFileSystem* fileSys;


};