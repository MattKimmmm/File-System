#pragma once

class AbstractCommand {
public:
	virtual ~AbstractCommand() = default;


	virtual int execute(std::string intput) = 0;
	virtual void displayInfo() = 0;

};