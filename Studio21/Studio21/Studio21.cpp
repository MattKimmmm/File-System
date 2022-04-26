// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/AbstractFile.h"
#include <iostream>

using namespace std;

int main()
{


	SimpleFileSystem* sys1 = new SimpleFileSystem();
	SimpleFileFactory* factory1 = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(sys1, factory1);

	CommandPrompt* cmdprompt = new CommandPrompt();

	cmdprompt->setFileFactory(factory1);
	cmdprompt->setFileSystem(sys1);
	cmdprompt->addCommand("touch", cmd);
	cmdprompt->run();

	AbstractFile* fileP =  sys1->openFile("file.txt");

	/*if (fileP != nullptr) {
		cout << "file Created!" << endl;
	}
	else {
		cout << "failure" << endl;
	}*/
	return 0;
}

