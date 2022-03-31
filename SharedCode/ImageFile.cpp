// definition of ImageFile class here

#include "ImageFile.h"

using namespace std;


ImageFile::ImageFile(string fileName) : name(fileName), size('0') {};

unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}