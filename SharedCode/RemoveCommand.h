#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand :public AbstractCommand {
private:
	
	AbstractFileSystem* fileSysPtr;

public:
	virtual int execute(std::string input) override;
	virtual void displayInfo() override;

	RemoveCommand(AbstractFileSystem * fileSys);


};