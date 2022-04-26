#pragma once
#include "AbstractCommand.h"

class AbstractFileSystem;
class AbstractFileFactory;

class TouchCommand : public AbstractCommand {
private:

	AbstractFileSystem* fileSysPtr;
	AbstractFileFactory* fileFacPtr;

public:

	TouchCommand(AbstractFileSystem* fileSys, AbstractFileFactory* fileFac);

	virtual void displayInfo() override;
	virtual int execute(std::string input) override;

};
