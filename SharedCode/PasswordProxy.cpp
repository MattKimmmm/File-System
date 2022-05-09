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
	cout << "Input Password: " << endl;
	getline(cin >> ws, pw);
	//cin >> pw;
	return pw;
}

bool PasswordProxy::checkPassword(string pw) {
	if (pw == password) {
		return true;
	}
	else {
		//cout << "Incorrect Password" << endl; // DEBUG PRINT DELETE LATERf
		
		return false;
	}
}

vector<char> PasswordProxy::read() {

	cout << "Please enter password to read this file" << endl;
	if (checkPassword(passwordPrompt())) {
		return filePtr->read();
	}
	else {
		vector<char> empty = {};
		return empty;
	}
}

int PasswordProxy::write(vector<char> v) {

	cout << "Please enter password to write to this file" << endl;
	if (checkPassword(passwordPrompt())) {
		return filePtr->write(v);
	}
	else {
		return noWriteAccess;
	}
}

int PasswordProxy::append(vector<char> v) {

	cout << "Please enter password to append to this file" << endl;
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

	cout << "Please enter password to call accept() on this file" << endl;
	if (checkPassword(passwordPrompt())) {
		filePtr->accept(absPtr);
	}
	
}

AbstractFile* PasswordProxy::clone(std::string fileName) {
	try {
		PasswordProxy* copiedFile = new PasswordProxy(filePtr->clone(fileName), password);
		return copiedFile;

	}
	catch(std::bad_alloc){
		return nullptr;
	}

}