
#include "ChmodProxy.h"
#include "SimpleFileSystem.h"
#include <iostream>

using namespace std;

ChmodProxy::ChmodProxy(AbstractFile* ptr) : filePtr(ptr) {};
ChmodProxy::~ChmodProxy() {
	delete filePtr;
};

void ChmodProxy::accept(AbstractFileVisitor* absPtr) {
	filePtr->accept(absPtr);
};

std::vector<char> ChmodProxy::read() {
	filePtr->read();
};
int ChmodProxy::write(std::vector<char> v) {
	cout << "This is a read-only file" << endl;
	return notSupported;
};

int ChmodProxy::append(std::vector<char> v) {
	cout << "This is a read-only file" << endl;
	return notSupported;
};

unsigned int ChmodProxy::getSize() {
	filePtr->getSize();
};

std::string ChmodProxy::getName() {
	filePtr->getName();
};


AbstractFile* ChmodProxy::clone(std::string fileName) {

};


