//  Define the TextFile class here
#pragma once

#include "TextFile.h"
#include <iostream>

TextFile::TextFile(std::string s) : fileName(s) {

};

unsigned int TextFile::getSize() {
	return static_cast<int>(content.size());
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

void TextFile::read() {

	for (auto i : content) {
		std::cout << i;
	}
	std::cout << std::endl;
}