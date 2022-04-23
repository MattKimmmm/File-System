#pragma once
#include "AbstractFile.h"
#include <string>
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* ptr, std::string pw);
	~PasswordProxy();
protected:
	std::string passwordPrompt();
	bool checkPassword(std::string pw);
private:
	AbstractFile* filePtr;
	std::string password;


};