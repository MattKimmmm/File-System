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
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "newParsingStrategy.h"
#include <iostream>

int main()
{

	SimpleFileSystem* sys1 = new SimpleFileSystem();
	SimpleFileFactory* factory1 = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(sys1, factory1);
	LSCommand* lsc = new LSCommand(sys1);
	RemoveCommand* rmc = new RemoveCommand(sys1);
	CatCommand* cat = new CatCommand(sys1);
	DisplayCommand* ds = new DisplayCommand(sys1);
	CopyCommand* cp = new CopyCommand(sys1);

	MacroCommand* rn = new MacroCommand(sys1);
	rn->addCommand(cp);
	rn->addCommand(rmc);
	RenameParsingStrategy* parser = new RenameParsingStrategy();
	rn->setParseStrategy(parser);

	MacroCommand* toc = new MacroCommand(sys1);
	toc->addCommand(cmd);
	toc->addCommand(cat);
	newParsingStrategy* tocParser = new newParsingStrategy();
	toc->setParseStrategy(tocParser);

	
	CommandPrompt* cmdprompt = new CommandPrompt();
	

	cmdprompt->setFileFactory(factory1);
	cmdprompt->setFileSystem(sys1);
	cmdprompt->addCommand("touch", cmd);
	cmdprompt->addCommand("ls", lsc);
	cmdprompt->addCommand("rm", rmc);
	cmdprompt->addCommand("cat", cat);
	cmdprompt->addCommand("ds", ds);
	cmdprompt->addCommand("cp", cp);
	cmdprompt->addCommand("rn", rn);
	cmdprompt->addCommand("toc", toc);
	int temp = cmdprompt->run();

	delete sys1, factory1, cmd, lsc, rmc,cat,ds,cp,rn,toc, cmdprompt;


	return 0;
}


