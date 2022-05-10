#pragma once

#include "AbstractFile.h"
#include <string>
class ChmodProxy : public AbstractFile {
public:
	ChmodProxy(AbstractFile* ptr);
	~ChmodProxy();

	void accept(AbstractFileVisitor* absPtr) override;

	std::vector<char> read() override;
	int write(std::vector<char> v) override;
	int append(std::vector<char> v) override;
	unsigned int getSize() override;
	std::string getName() override;
	virtual AbstractFile* clone(std::string fileName) override;






private:
	AbstractFile* filePtr;



};