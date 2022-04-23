#pragma once
#include "AbstractFile.h"
#include <string>
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* ptr, std::string pw);
	~PasswordProxy();

	void accept(AbstractFileVisitor* absPtr) override;

	std::vector<char> read() override;
	int write(std::vector<char> v) override;
	int append(std::vector<char> v) override;
	unsigned int getSize() override;
	std::string getName() override;


protected:
	std::string passwordPrompt();
	bool checkPassword(std::string pw);
private:
	AbstractFile* filePtr;
	std::string password;


};