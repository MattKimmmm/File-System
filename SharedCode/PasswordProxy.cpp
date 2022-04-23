/*
PasswordProxy(AbstractFile* ptr, std::string pw);
~PasswordProxy();
protected:
	std::string passwordPrompt();
private:
	AbstractFile* filePtr;
	std::string password;
*/

#include "PasswordProxy.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* ptr, string pw) : filePtr(ptr), password(pw) {

}

PasswordProxy::~PasswordProxy() {
	delete filePtr;
}
string PasswordProxy::passwordPrompt() {
	string pw = "";
	cout << "Input Password: ";
	cin >> pw;
	return pw;
}

bool PasswordProxy::checkPassword(string pw) {
	if (pw == password) {
		return true;
	}
	else {
		cout << "Incorrect Password" << endl; // DEBUG PRINT DELETE LATER
		//checkPassword(passwordPrompt());
		return false;
	}
}

vector<char> PasswordProxy::read() {

	if (checkPassword(passwordPrompt())) {
		return filePtr->read();
	}
	else {
		vector<char> empty = {};
		return empty;
	}
}

int PasswordProxy::write(vector<char> v) {

	if (checkPassword(passwordPrompt())) {
		return filePtr->write(v);
	}
	else {
		return noWriteAccess;
	}
}

int PasswordProxy::append(vector<char> v) {

	if (checkPassword(passwordPrompt())) {
		return filePtr->append(v);
	}
	else {
		return noAppendAccess;
	}
}

unsigned int PasswordProxy::getSize() {
	return filePtr->getSize();
}

string PasswordProxy::getName() {
	return filePtr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* absPtr) {
	if (checkPassword(passwordPrompt())) {
		filePtr->accept(absPtr);
	}
	
}