// definition of ImageFile class here

#include "ImageFile.h"
#include "SimpleFileSystem.h"
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

	cout << "Size is : " << size << endl;

	int sizeNum = size - '0';

	if (pow(sizeNum, 2) != v.size() - 1) {
		size = 0;
		contents.clear();
		return sizeMismatch;
	}

	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] == 'X' || v[i] == ' ') {
			contents.push_back(v[i]);
		}
		else {
			size = 0;
			contents.clear();
			return emptyImage;
		}
	}
	return success;
}

int ImageFile::append(std::vector<char> v) {
	return notSupported;
}

vector<char> ImageFile::read() {
	
	return contents;

	/*
	int board_size = size - '0';
	
	for (int i = 0; i < board_size; ++i) {

		for (int j = 0; j < board_size; j++) {

			int index = j * board_size + i;
			cout << contents[index];
		}
		cout << endl;
	}

	*/
}
