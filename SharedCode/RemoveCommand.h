#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand :public AbstractCommand {
private:
	
	AbstractFileSystem* fileSysPtr;

public:
	virtual int execute(std::string intput);
	virtual void displayInfo();

	RemoveCommand(AbstractFileSystem * fileSys);


};