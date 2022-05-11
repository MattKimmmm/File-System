#pragma once

#include "AbstractCommand.h"
class AbstractFileSystem;

class ChmodCommand : public AbstractCommand {

public:

	ChmodCommand(AbstractFileSystem* sys);

	int execute(std::string intput);
	void displayInfo();

private:
	AbstractFileSystem* fileSys;


};