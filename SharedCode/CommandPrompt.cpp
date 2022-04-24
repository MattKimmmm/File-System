

#include "CommandPrompt.h"
#include "SimpleFileSystem.h"

#include <iostream>

using namespace std;

CommandPrompt::CommandPrompt() : fileSys(nullptr), fileFac(nullptr){
};




void CommandPrompt::CommandPrompt::listCommands() {
	

};


std::string CommandPrompt::prompt() {

	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for ";
	cout <<	"more information about that command. \n $ ";

	string userInput;
	getline(cin, userInput);

	return userInput;

};






void CommandPrompt::setFileSystem(AbstractFileSystem* fileSystem) {
	fileSys = fileSystem;
};

void CommandPrompt::setFileFactory(AbstractFileFactory* fileFactory) {

	fileFac = fileFactory;

};

int CommandPrompt::addCommand(std::string cmd, AbstractCommand* absCmd) {

	if (commands.insert(make_pair(cmd, absCmd)).second == true) {

		return success;
	}
	else {
		return addCommandFailure;
	}

};
 int run();


 void CommandPrompt::listCommands() {

	 for (auto i : commands) {

		 cout << i.first << endl;

	 }
 };
