//  Define the TextFile class here
#pragma once

#include "TextFile.h"
#include <iostream>
#include "AbstractFileVisitor.h"

TextFile::TextFile(std::string s) : fileName(s) {

};

unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(content.size());
}

std::string TextFile::getName() {
	return fileName;
}

int TextFile::write(std::vector<char> v) {
	
	content = v;
	return 0;
}

int TextFile::append(std::vector<char> v) {
	
	for (auto i : v) {
		content.push_back(i);
	}
	return 0;

}

std::vector<char> TextFile::read() {

	return content;

	/*
	
	*/
}

void TextFile::accept(AbstractFileVisitor* filePtr) {
	filePtr->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string fileName) {
	std::string copyName = fileName + ".txt";
	TextFile* newCopy = new TextFile(copyName);
	newCopy->write(content);

	return newCopy;
}