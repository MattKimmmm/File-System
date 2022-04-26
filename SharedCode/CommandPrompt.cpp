

#include "CommandPrompt.h"
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"

#include <iostream>
#include <sstream>

using namespace std;

CommandPrompt::CommandPrompt() : fileSys(nullptr), fileFac(nullptr){
};




void CommandPrompt::CommandPrompt::listCommands() {
	
	for (auto i : commands) {

		cout << i.first << endl;

	}

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

		return successful;
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

					if (retCode != successful) {
						cout << "Command failed" << endl;
					}

					//return retCode;
				
				}
				else {
					cout << "Command not found" << endl;

					//return commandNotFound;
				}


			}
			//The input is longer than one word
			else {
				istringstream iss = istringstream(result);
				string firstWord;

				//Extract the first word
				iss >> firstWord;

				

				//Check if the first word is "help"
				if (firstWord == "help") {

					//Extract the second word
					string secondWord;
					iss >> secondWord;

					auto cmdReturn = commands.find(secondWord);

					//If the command is not found in the map
					if (cmdReturn == commands.end()) {
						cout << "Command does not exist" << endl;
						//return commandNotFound;
					}
					//If the command is found, call displayInfo()
					else {
						cmdReturn->second->displayInfo();
						//return successful;
					}

				}
				//If the first word is not "help"--we are dealing with a command name
				else {

					auto cmdReturn = commands.find(firstWord);

					//If the command is not found in the map
					if (cmdReturn == commands.end()) {
						cout << "Command does not exist" << endl;
						//return commandNotFound;
					}
					//If the command is found, call execute()
					else {

						string word;
						string restOfInput;
						while (iss >> word) {
							restOfInput += word;
							restOfInput += " ";
							
						}

						//Get rid of the newline character at the end
						if (!restOfInput.empty()) {
							restOfInput.pop_back();
						}
						

						int cmdReturnCode = cmdReturn->second->execute(restOfInput);

						if (cmdReturnCode != successful) {

							cout << "Command execution failure" << endl;
							//return cmdReturnCode;
						}

						//return successful;
					}

				}


			}


		}


	}

};


