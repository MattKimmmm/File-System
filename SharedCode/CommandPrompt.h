#pragma once
#include <map>
#include<string>

class AbstractCommand;
class AbstractFileSystem;
class AbstractFileFactory;

class CommandPrompt {
private:
	std::map<std::string, AbstractCommand*> commands;
	AbstractFileSystem* fileSys;
	AbstractFileFactory* fileFac;

protected:

	void listCommands();
	std::string prompt();


public:

	CommandPrompt();
	virtual ~CommandPrompt() = default;

	virtual void setFileSystem(AbstractFileSystem* fileSystem);
	virtual void setFileFactory(AbstractFileFactory* fileFactory);
	virtual int addCommand(std::string cmd, AbstractCommand* absCmd);
	virtual int run();



};