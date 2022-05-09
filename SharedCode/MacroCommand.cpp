#include "MacroCommand.h"

using namespace std;
MacroCommand::MacroCommand(AbstractFileSystem* fileSys) :fileSysPtr(fileSys), commandList({}), cmdParser(nullptr){
};

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	cmdParser = strategy;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
	commandList.push_back(cmd);
}

int MacroCommand::execute(string input) {
	vector<string> inputs = cmdParser->parse(input);
	int index = 0;
	for (AbstractCommand* cmd : commandList) {
		int executeResult = cmd->execute(inputs[index]);
		if (executeResult != successful) {
			displayInfo();
			return executeResult;
		}
		index++;
	}
	
	return successful;
}

void MacroCommand::displayInfo() {
	cout << "you can combine commands" << endl;
}
