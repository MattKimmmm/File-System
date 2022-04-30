// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/CatCommand.h"
#include <iostream>

int main()
{

	SimpleFileSystem* sys1 = new SimpleFileSystem();
	SimpleFileFactory* factory1 = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(sys1, factory1);
	LSCommand* lsc = new LSCommand(sys1);
	RemoveCommand* rmc = new RemoveCommand(sys1);
	CatCommand* cat = new CatCommand(sys1);


	CommandPrompt* cmdprompt = new CommandPrompt();
	

	cmdprompt->setFileFactory(factory1);
	cmdprompt->setFileSystem(sys1);
	cmdprompt->addCommand("touch", cmd);
	cmdprompt->addCommand("ls", lsc);
	cmdprompt->addCommand("rm", rmc);
	cmdprompt->addCommand("cat", cat);
	int temp = cmdprompt->run();

	delete sys1, factory1, cmd, lsc, rmc, cmdprompt;


	return 0;
}


