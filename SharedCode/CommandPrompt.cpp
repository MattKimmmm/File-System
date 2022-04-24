

#include "CommandPrompt.h"
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"

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
int CommandPrompt::run() {

	

	while (1) {

		string result = prompt();

		if (result == "q") {
			return userQuit;
		}
		else if(result == "help") {
			listCommands();
		}
		else {

			//Check if the input is one word: " " exists means more than one word
			if (result.find(" ") == -1) {

				if (commands.find(result) != commands.end()) {
					
					
					int retCode = commands.find(result)->second->execute("");

					if (retCode != success) {
						cout << "Command failed" << endl;
					}

					return retCode;
				
				}
				else {
					cout << "Command not found" << endl;

					return commandNotFound;
				}


			}
			else {


			}



		}


	}

};


 void CommandPrompt::listCommands() {

	 for (auto i : commands) {

		 cout << i.first << endl;

	 }
 };
