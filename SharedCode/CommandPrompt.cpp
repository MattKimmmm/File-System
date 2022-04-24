

#include "CommandPrompt.h"
#include "SimpleFileSystem.h"

using namespace std;

CommandPrompt::CommandPrompt() : fileSys(nullptr), fileFac(nullptr){
};




void CommandPrompt::CommandPrompt::listCommands() {s

}
std::string prompt();






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
