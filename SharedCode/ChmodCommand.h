#pragma once

#include "AbstractCommand.h"
class AbstractFileSystem;

class ChmodCommand : public AbstractCommand {

public:

	ChmodCommand(AbstractFileSystem* sys);

	virtual int execute(std::string intput);
	virtual void displayInfo();

private:
	AbstractFileSystem* fileSys;


};