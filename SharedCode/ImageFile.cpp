// definition of ImageFile class here

#include "ImageFile.h"
#include <iostream>
using namespace std;


ImageFile::ImageFile(string fileName) : name(fileName), size('0') {};

unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> v) {
	size = *(v.end() - 1);

	int sizeNum = size - '0';

	if (sizeNum != v.size() - 1) {
		size = '0';
		contents.clear();
		return failure;
	}

	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] == 'X' || v[i] == ' ') {
			contents.push_back(v[i]);
		}
		else {
			size = '0';
			contents.clear();
			return failure;
		}
	}
	return success;
}

int ImageFile::append(std::vector<char> v) {
	return notSupported;
}

void ImageFile::read() {
	int board_size = size - '0';
	for (int i = board_size; i > 0; i--) {
		for (int j = 0; j < board_size; j++) {
			int index = i * board_size + j;
			cout << contents[index];
		}
		cout << endl;
	}
}
