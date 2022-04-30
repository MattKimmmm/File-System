#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
#include <vector>


class TextFile : public AbstractFile {
private:
	std::vector<char> content;

	std::string fileName;

protected:
	virtual void accept(AbstractFileVisitor* filePtr) override;

public:

	TextFile(std::string s);
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char> v) override;
	virtual int append(std::vector<char> v) override;
	virtual std::vector<char> read() override;

	

};