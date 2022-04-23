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
		filePtr->read();
	}
	else {
		vector<char> empty = {};
		return empty;
	}
}

int PasswordProxy::write(vector<char> v) {

	if (checkPassword(passwordPrompt())) {
		filePtr->write(v);
	}
	else {
		return noWriteAccess;
	}
}

int PasswordProxy::append(vector<char> v) {

	if (checkPassword(passwordPrompt())) {
		filePtr->append(v);
	}
	else {
		return noAppendAccess;
	}
}