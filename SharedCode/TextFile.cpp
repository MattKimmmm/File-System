//  Define the TextFile class here
#pragma once

#include "TextFile.h"
#include <iostream>

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
	for (auto i : content) {
		std::cout << i;
	}
	std::cout << std::endl;

	*/
}