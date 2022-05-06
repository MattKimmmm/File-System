// definition of ImageFile class here

#include "ImageFile.h"
#include "SimpleFileSystem.h"
#include "AbstractFileVisitor.h"

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

	vector<char> original_img = contents;
	char original_size = size;
	contents.clear();
	char sizeTemp = *(v.end() - 1);
	int sizeNum = sizeTemp - '0';
	
	if (pow(sizeNum, 2) != v.size() - 1) {
		//size = 0;
		//contents.clear();
		contents = original_img;
		return sizeMismatch;
	}
	else {
		size = sizeTemp;
	}
	
	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] == 'X' || v[i] == ' ') {
			contents.push_back(v[i]);
		}
		else {
			size = original_size;
			contents.clear();
			contents = original_img;
			return emptyImage;
		}
	}
	return successful;
}

int ImageFile::append(std::vector<char> v) {
	return notSupported;
}

vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* absPtr) {
	return absPtr->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string fileName) {
	
	//REQUIRE ACTUAL IMPLEMENTATION

	AbstractFile* filePtr =  nullptr;
	
	return filePtr;

}