#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include "LSCommand.h"
#include "CatCommand.h"
#include "RemoveCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "SimpleFileSystem.h"

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSysPtr;
	std::vector<AbstractCommand*> commandList;
	AbstractParsingStrategy* cmdParser;

public:
	MacroCommand(AbstractFileSystem* fileSys);

	int execute(std::string input) override;
	void displayInfo() override;

	void addCommand(AbstractCommand* cmd);
	void setParseStrategy(AbstractParsingStrategy* strategy);
};
